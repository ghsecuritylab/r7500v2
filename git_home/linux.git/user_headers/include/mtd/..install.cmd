cmd_/home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/mtd/.install := perl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/sourcecode/scripts/headers_install.pl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/sourcecode/include/mtd /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/mtd arm inftl-user.h mtd-abi.h mtd-user.h nftl-user.h ubi-user.h; perl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/sourcecode/scripts/headers_install.pl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/include/mtd /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/mtd arm ; perl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/sourcecode/scripts/headers_install.pl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/include/generated/mtd /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/mtd arm ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/mtd/$$F; done; touch /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/mtd/.install