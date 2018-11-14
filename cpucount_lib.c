#include <stdio.h>
#include <unistd.h>

int get_num_cpu_cores(void) {
        int num_cpu_cores_configured = sysconf(_SC_NPROCESSORS_CONF);
        int num_cpu_cores_online = sysconf(_SC_NPROCESSORS_ONLN);

        return num_cpu_cores_online;
}
