CC=gcc
CFLAGS = -Wall -g

pthread_cond_sample.bin: pthread_cond_sample/pthread_cond_sample.c
	$(CC) $(CFLAGS) $< -o $(dir $<)/$@

simple_callback.bin: simple_callback/simple_callback.c
	$(CC) $(CFLAGS) $< -o $(dir $<)/$@

s_event_loop.bin: s_event_loop/s_event_loop.c
	$(CC) $(CFLAGS) $< -o $(dir $<)/$@

timer_io_loop.bin: timer_io_loop/timer_io_loop.c
	$(CC) $(CFLAGS) $< -o $(dir $<)/$@
# .PHONY: all test clean

clean:
	rm ./*/*.bin