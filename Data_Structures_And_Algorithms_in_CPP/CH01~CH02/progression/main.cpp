#include "progression.h"

int main()
{
    Progression *prog;

    cout << "Arithmetic progression with default increment:\n";
    prog = new ArithProgression();
    prog->PrintProgression(10);

    cout << "Arithmetic progression with increment 5:\n";
    prog = new ArithProgression(5);
    prog->PrintProgression(10);

    cout << "Geometric progression with default base:\n";
    prog = new GeomProgression();
    prog->PrintProgression(10);

    cout << "Geometric progression with base 3:\n";
    prog = new GeomProgression(3);
    prog->PrintProgression(10);

    cout << "Fibonacci progression with default base:\n";
    prog = new FibonacciProgression();
    prog->PrintProgression(10);

    cout << "Fibonacci progression with base 3:\n";
    prog = new FibonacciProgression(4, 6);
    prog->PrintProgression(10);
    return EXIT_SUCCESS;
}