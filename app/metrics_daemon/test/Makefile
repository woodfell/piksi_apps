TARGET=run_metrics_daemon_test

SOURCES= \
	run_metrics_daemon_test.cc

LIBS= \
	-ljson-c -luv -lsbp -lpiksi -ldl -lpthread -lsettings -lgtest \
	../src/metrics_daemon.a

CFLAGS=-std=gnu++11 -z muldefs -I../src

CROSS=

CC=$(CROSS)g++

all: program
program: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) $(LIBS)

clean:
	rm -rf $(TARGET)
