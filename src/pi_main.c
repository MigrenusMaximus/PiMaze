#include <errno.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

/* ================ */

int set_interface_attribs (int fd, int speed, int parity) {
    struct termios tty;
    memset (&tty, 0, sizeof(tty));
    if (tcgetattr (fd, &tty) != 0) {
        //error_message ("error %d from tcgetattr", errno);
        return -1;
    }

    cfsetospeed (&tty, speed);
    cfsetispeed (&tty, speed);

    tty.c_cflag = (tty.c_cflag & ~CSIZE) | CS8;     // 8-bit chars
    // disable IGNBRK for mismatched speed tests; otherwise receive break
    // as \000 chars
    tty.c_iflag &= ~IGNBRK;         // disable break processing
    tty.c_lflag = 0;                // no signaling chars, no echo,
                                    // no canonical processing
    tty.c_oflag = 0;                // no remapping, no delays
    tty.c_cc[VMIN]  = 0;            // read doesn't block
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // shut off xon/xoff ctrl

    tty.c_cflag |= (CLOCAL | CREAD);// ignore modem controls,
                                    // enable reading
    tty.c_cflag &= ~(PARENB | PARODD);      // shut off parity
    tty.c_cflag |= parity;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CRTSCTS;

    if (tcsetattr (fd, TCSANOW, &tty) != 0) {
        //error_message ("error %d from tcsetattr", errno);
        return -1;
    }
    return 0;
}

void set_blocking (int fd, int should_block) {
    struct termios tty;
    memset (&tty, 0, sizeof(tty));
    if (tcgetattr (fd, &tty) != 0) {
        //error_message ("error %d from tggetattr", errno);
        return;
    }

    tty.c_cc[VMIN]  = should_block ? 1 : 0;
    tty.c_cc[VTIME] = 5;            // 0.5 seconds read timeout

    if (tcsetattr (fd, TCSANOW, &tty) != 0)
        ;//error_message ("error %d setting term attributes", errno);
}

/* ================ */

int main(int argc, char **argv) {
	char portname[20] = "/dev/";
    
	if (argv[1] == NULL) {
		printf("Usage: ./pi_main <serial_port>\n");
		return -1;
	}
	else {
		strcat(portname, argv[1]);
    }
    
	printf("Listening on port %s\n", portname);

	int fd = open (portname, O_RDWR | O_NOCTTY | O_SYNC);

	if (fd < 0) {
	    printf("Greska\n");
	    //error_message ("error %d opening %s: %s", errno, portname, strerror (errno));
	    return 0;
	}
    
    Game game = setGame(10, 10);
    printGame(&newGame);
    
	set_interface_attribs (fd, B115200, 0);  // set speed to 115,200 bps, 8n1 (no parity)
	set_blocking (fd, 0);                    // set no blocking
    
    for (int i = 0; i < game.maze->height; i++) {
        for (int j = 0; j < game.maze->width; j++) {
            write(fd, game.maze->blocks[i * game.maze->width + j].isWall == TRUE ? "W" : " ", 1);
        }
    }
    usleep ((23 * 23 + 6) * 100); // cekamo da se posalje i da primimo joystate

	char buf [6];
	int n = read (fd, buf, sizeof(buf));     // read up to 100 characters if ready to read
	printf("%s\n", buf);
	printf("Done\n");
	return 0;
}
