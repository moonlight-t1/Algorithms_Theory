#include <stdio.h>
#include <stdlib.h>
#include "SimDef.h"
#include "SimLinkedQueue.h"
#include "SimUtil.h"

int main(int argc, char *argv[])
{
    int currentTime = 0;      // 현재 시각
    int endTime = 10;         // 시뮬레이션 종료 시각
    int serviceUserCount = 0; // 고객의 수
    int totalWaitTime = 0;    // 모든 대기 시간(Wait time의 합)

    LinkedQueue *pArrivalQueue = NULL; // 고객 도착 큐
    LinkedQueue *pWaitQueue = NULL;    // 고객 대기 큐
    QueueNode *pServiceNode1 = NULL;   // 현재 서비스 중인 고객(노드)

    pArrivalQueue = createLinkedQueue();
    pWaitQueue = createLinkedQueue();
    if (pArrivalQueue != NULL && pWaitQueue == NULL)
    {
        printf("Error. createLinkedQueue()\n");
        return FALSE;
    }

    // 고객 도착 큐 설정
    insertCustomer(0, 3, pArrivalQueue); // 도착 시각 : 0, 서비스 시간 : 3
    insertCustomer(2, 2, pArrivalQueue); // 도착 시각 : 2, 서비스 시간 : 2
    insertCustomer(4, 1, pArrivalQueue); // 도착 시각 : 4, 서비스 시간 : 1
    insertCustomer(6, 1, pArrivalQueue); // 도착 시각 : 6, 서비스 시간 : 1
    insertCustomer(8, 3, pArrivalQueue); // 도착 시각 : 8, 서비스 시간 : 3

    // 실제 시뮬레이션의 메인 루틴
    for (currentTime = 0; currentTime < endTime; currentTime++)
    {
        // 고객 도착
        processArrival(currentTime, pArrivalQueue, pWaitQueue);

        // 서비스 종료 처리
        if (pServiceNode1 != NULL)
        {
            pServiceNode1 = processServiceNodeEnd(currentTime, pServiceNode1, &serviceUserCount, &totalWaitTime);
        }

        // 서비스 시작 처리
        if (pServiceNode1 == NULL)
        {
            pServiceNode1 = processServiceNodeStart(currentTime, pWaitQueue);
        }

        // 대기 큐의 상태 출력
        printWaitQueueStatus(currentTime, pWaitQueue);
    }

    // 최종 시뮬레이션 결과 출력
    printReport(pWaitQueue, serviceUserCount, totalWaitTime);

    // 메모리 해제
    if (pServiceNode1 != NULL)
    {
        free(pServiceNode1);
    }

    deleteLinkedQueue(pArrivalQueue);
    deleteLinkedQueue(pWaitQueue);

    return 0;
}