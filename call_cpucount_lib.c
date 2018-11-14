#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#define SHARED_CPU_LIB "./cpucount_lib.so"

int main() {
        int num_cpu_cores;
        void *cpucount_lib;
        int (*ext_get_num_cpu_cores)(void);
 
        cpucount_lib = dlopen(SHARED_CPU_LIB, RTLD_LAZY);
        if (cpucount_lib != NULL) {
                /* 
                 * `man dlopen` says that C99 standard leaves casting from
                 * `void *` to a function pointer undefined. The following is
                 * the POSIX.1-2003 workaround found in man page. See also the
                 * following StackOverflow answer:
                 * https://stackoverflow.com/a/19487645/236007
                 */
                 *(void **)(&ext_get_num_cpu_cores) = dlsym(cpucount_lib, "get_num_cpu_cores");                
                num_cpu_cores = ext_get_num_cpu_cores();
        } else {
                printf("ERROR opening the shared library %s!\n", SHARED_CPU_LIB);
                return ELIBACC; // "Can not access a needed shared library."
        }

        printf("Number of CPU cores: %d\n", num_cpu_cores);

        dlclose(cpucount_lib);
        
        return EXIT_SUCCESS;
}
