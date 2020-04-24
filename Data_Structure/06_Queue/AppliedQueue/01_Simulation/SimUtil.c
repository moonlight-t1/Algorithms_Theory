#include <stdio.h>
#include <stdlib.h>
#include "SimDef.h"
#include "SimLinkedQueue.h"
#include "SimUtil.h"

// 고객 도착 큐에 고객 추가
void insertCustomer(int arrivalTime, int serviceTime, LinkedQueue *pQueue)
{
    int i = 0;
    if (pQueue != NULL)
    {
        QueueNode node = {
            0,
        };
        node.data.status = arrival;
        node.data.arrivalTime = arrivalTime;
        node.data.serviceTime = serviceTime;
        node.data.startTime = 0;
        node.data.endTime = 0;
        enqueueLQ(pQueue, node);
    }
}

// 고객 도착 처리
void processArrival(int currentTime, LinkedQueue *pArrivalQueue, LinkedQueue *pWaitQueue)
{
    QueueNode *pArrivalNode = NULL;
    int isEmpty = 0;

    // 고객 도착 큐에 더 이상 노드가 없는지 확인하며, 없으면 루프를 빠져나온다
    isEmpty = isLinkedQueueEmpty(pArrivalQueue);
    while (isEmpty == FALSE)
    {
        // 현재 '고객 도착 큐'의 프런트 노드(고객)을 피크한다
        pArrivalNode = peekLQ(pArrivalQueue);

        // 피크된 고객의 도착 시간이 현재 시각과 같은지를 확인한다
        if (pArrivalNode->data.arrivalTime == currentTime)
        {
            enqueueLQ(pWaitQueue, *pArrivalNode);
            // 만약 같다면 '고객 대기 큐'에 인큐하고, 대기 상태가 되었음을 출력한다
            printSimCustomer(currentTime, pArrivalNode->data);
            // 기존의 '고객 도착 큐'에서는 삭제시키고, 메모리를 해제시킨다.
            free(dequeueLQ(pArrivalQueue));
        }
        else
        {
            break;
        }
        isEmpty = isLinkedQueueEmpty(pArrivalQueue);
    }
}

// 서비스 시작 처리
QueueNode *processServiceNodeStart(int currentTime, LinkedQueue *pWaitQueue)
{
    QueueNode *pReturn = NULL;
    QueueNode *pServiceNode = NULL;
    int isEmpty = 0;

    if (pWaitQueue == NULL)
    {
        return NULL;
    }

    isEmpty = isLinkedQueueEmpty(pWaitQueue);
    if (isEmpty == FALSE)
    {
        // 현재 고객 대기 큐 pWaitQueue에서 디큐 실행
        pServiceNode = dequeueLQ(pWaitQueue);

        if (pServiceNode != NULL)
        {
            pServiceNode->data.status = start;                 // 고객(노드)의 상태를 서비스 시작 상태로 변경
            pServiceNode->data.startTime = currentTime;        // 서비스 시작 시각을 현재 시각으로 설정
            printSimCustomer(currentTime, pServiceNode->data); // 고객의 정보를 출력

            pReturn = pServiceNode;
        }
    }
    return pReturn;
}

// 서비스 종료 처리
QueueNode *processServiceNodeEnd(int currentTime, QueueNode *pServiceNode, int *pServiceUserCount, int *pTotalWaitTime)
{
    int endTime = 0;
    int waitTime = 0;
    QueueNode *pReturn = NULL;

    if (pServiceNode == NULL || pServiceUserCount == NULL || pTotalWaitTime == NULL)
    {
        return NULL;
    }

    // 종료 처리
    endTime = pServiceNode->data.startTime + pServiceNode->data.serviceTime;
    if (endTime <= currentTime)
    {
        waitTime = pServiceNode->data.startTime - pServiceNode->data.arrivalTime;

        (*pServiceUserCount)++;
        (*pTotalWaitTime) += waitTime;

        pServiceNode->data.status = end;
        pServiceNode->data.endTime = currentTime;
        printSimCustomer(currentTime, pServiceNode->data);

        free(pServiceNode);
        pReturn = NULL;
    }
    else
    {
        // do nothing
        pReturn = pServiceNode;
    }
    return pReturn;
}

// 고객의 상태를 출력
void printSimCustomer(int currentTime, SimCustomer customer)
{
    printf("[%d]: ", currentTime);

    switch (customer.status)
    {
    case arrival:
        printf("Customer Arrived\n");
        break;

    case start:
        printf("Service Start");
        printf(" : Arrival Time - %d, Waiting Time - %d\n", customer.arrivalTime, (customer.startTime - customer.arrivalTime));
        break;

    case end:
        printf("Service End");
        printf(" : Arrival Time - %d, Start Time - %d, Waiting Time - %d, Serivice Time - %d\n", customer.arrivalTime, customer.startTime, customer.startTime - customer.arrivalTime, customer.endTime - customer.startTime);
        break;
    }
}

// 대기 열의 상태를 출력
void printWaitQueueStatus(int currentTime, LinkedQueue *pWaitQueue)
{
    printf("[%d]: Current Waiting Customers : %d\n", currentTime, pWaitQueue->currentElementCount);
}

// 최종 시뮬레이션 결과(통계치) 출력
void printReport(LinkedQueue *pWaitQueue, int serviceUserCount, int totalWaitTime)
{
    printf("REPORT\n");
    printf("The number of customers : %d\n", serviceUserCount);
    if (serviceUserCount > 0)
    {
        printf("Average Waiting Time : %f\n", ((float)totalWaitTime / (float)serviceUserCount));
    }
    printf("Current Waiting Customers : %d\n", pWaitQueue->currentElementCount);
}