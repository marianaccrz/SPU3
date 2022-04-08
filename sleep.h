#include <time.h>
void sleep(size_t m_s){
    m_s = m_s/1000;
    clock_t initial_time = time(NULL); //Tiempo inicial//
    clock_t desired_time = initial_time + m_s ;
    for(clock_t current_time = initial_time; current_time < desired_time; current_time = time(NULL) ){};
}
