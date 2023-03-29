// Paralelização de código Hello World! usando a API OpenMP
#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#   include <omp.h>
#endif   

void Hello(void);  /* Função Thread */

/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
   int thread_count = strtol(argv[1], NULL, 10); /* Função Strtol para obter o número de threads*/

#  pragma omp parallel num_threads(thread_count) /* Diretiva para paralelização do número de threads*/
   Hello();
// A cada interação é feita a chamada para a função Hello
   return 0; 
}  /* main */

/*-------------------------------------------------------------------
 * Função:    Hello
 * Propósito:     Função da thread que imprime a mensagem
 */
void Hello(void) {
#  ifdef _OPENMP   /* Verificação se _OPENMP foi validado*/
      int my_rank = omp_get_thread_num();
      int thread_count = omp_get_num_threads();
#  else /* Caso não seja teremos uma thread única*/
      int my_rank = 0;
      int thread_count = 1;
#  endif
   printf("Hello from thread %d of %d\n", my_rank, thread_count);

}  /* Hello */