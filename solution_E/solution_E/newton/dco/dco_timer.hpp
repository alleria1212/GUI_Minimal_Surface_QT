// dco::timer is an (as) accurate (as possible) wallclock timer used for performance analysis
// as we (as well as our users) are often interested in timing sth, we
// decided to include the timer in dco.

// dco::timer T; T.start(); T.elapsed(); T.restart(); ...

#ifndef DCO_TIMER_HPP_
#define DCO_TIMER_HPP_

#include <time.h>
#include <unistd.h>


namespace dco {

class timer {
private:
    double time;
    timespec start_time;
    bool running;

    timespec diff(const timespec start_time, const timespec end) const {
        timespec temp;
        if ((end.tv_nsec - start_time.tv_nsec) < 0) {
            temp.tv_sec = end.tv_sec - start_time.tv_sec - 1;
            temp.tv_nsec = 1000000000 + end.tv_nsec - start_time.tv_nsec;
        } else {
            temp.tv_sec = end.tv_sec - start_time.tv_sec;
            temp.tv_nsec = end.tv_nsec - start_time.tv_nsec;
        }
        return temp;
    }

public:

    timer() {
        start();
    }

    static void sleep(const double seconds) {
        usleep(static_cast<useconds_t>(seconds * 1000 * 1000));
    }

    void start() {
        time = 0.0;
        running = true;
        clock_gettime(0, &start_time);
    }

    void stop() {
        if(running) {
            running = false;
            timespec gettime, difftime;

            clock_gettime(0, &gettime);
            difftime = diff(start_time, gettime);

            time += static_cast<double>(difftime.tv_sec) + static_cast<double>(difftime.tv_nsec) * 1e-9;
        }
    }

    void restart() {
        start();
    }

    void resume() {
        running = true;
        clock_gettime(0, &start_time);
    }

    double get() {
        return elapsed();
    }

    double elapsed() {
        if(running) {
            timespec gettime, difftime;

            clock_gettime(0, &gettime);
            difftime = diff(start_time, gettime);
            return time + static_cast<double>(difftime.tv_sec) + static_cast<double>(difftime.tv_nsec) * 1e-9;
        } else {
            return time;
        }
    }
};
}
#endif
