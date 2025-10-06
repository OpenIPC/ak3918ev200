GCC = arm-shivaya-linux-uclibcgnueabi-gcc

conf_info:
	gcc -Wall -o bin/conf_info src/conf/{dump_isp_conf.c,parse_isp_conf.c}

stream_setup_test:
	$(GCC) -Os -pthread -Wall -o bin/stream_setup_test src/stream/stream_setup_test.c
