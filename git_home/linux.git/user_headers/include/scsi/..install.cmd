cmd_/home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/scsi/.install := perl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/sourcecode/scripts/headers_install.pl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/sourcecode/include/scsi /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/scsi arm scsi_bsg_fc.h scsi_netlink.h scsi_netlink_fc.h; perl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/sourcecode/scripts/headers_install.pl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/include/scsi /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/scsi arm ; perl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/sourcecode/scripts/headers_install.pl /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/include/generated/scsi /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/scsi arm ; for F in ; do echo "\#include <asm-generic/$$F>" > /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/scsi/$$F; done; touch /home/roger.luo/auto-gpl/tmp/linux/linux-3.4.103/user_headers/include/scsi/.install