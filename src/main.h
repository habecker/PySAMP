#ifndef MAIN_H
#define MAIN_H

#define PY_TEST (0)
#define SAMPGDK_MIN_LOG_LEVEL 0

#ifndef WIN32
    #include <dlfcn.h>
#endif

#include <string.h>
#include "sampgdk.h"
#include "config.h"
#include "pysamp.h"

#define PYSAMP_LOADING_SCREEN_1 \
"\
           PPPPPPPPPPPPPPPPP                               SSSSSSSSSSSSSSS              AAA               MMMMMMMM               MMMMMMMMPPPPPPPPPPPPPPPPP   \n\
           P::::::::::::::::P                            SS:::::::::::::::S            A:::A              M:::::::M             M:::::::MP::::::::::::::::P  \n\
           P::::::PPPPPP:::::P                          S:::::SSSSSS::::::S           A:::::A             M::::::::M           M::::::::MP::::::PPPPPP:::::P \n\
           PP:::::P     P:::::P                         S:::::S     SSSSSSS          A:::::::A            M:::::::::M         M:::::::::MPP:::::P     P:::::P\n\
             P::::P     P:::::Pyyyyyyy           yyyyyyyS:::::S                     A:::::::::A           M::::::::::M       M::::::::::M  P::::P     P:::::P\
"

#define PYSAMP_LOADING_SCREEN_2 \
"\
  P::::P     P:::::P y:::::y         y:::::y S:::::S                    A:::::A:::::A          M:::::::::::M     M:::::::::::M  P::::P     P:::::P\n\
             P::::PPPPPP:::::P   y:::::y       y:::::y   S::::SSSS                A:::::A A:::::A         M:::::::M::::M   M::::M:::::::M  P::::PPPPPP:::::P \n\
             P:::::::::::::PP     y:::::y     y:::::y     SS::::::SSSSS          A:::::A   A:::::A        M::::::M M::::M M::::M M::::::M  P:::::::::::::PP  \n\
             P::::PPPPPPPPP        y:::::y   y:::::y        SSS::::::::SS       A:::::A     A:::::A       M::::::M  M::::M::::M  M::::::M  P::::PPPPPPPPP    \n\
             P::::P                 y:::::y y:::::y            SSSSSS::::S     A:::::AAAAAAAAA:::::A      M::::::M   M:::::::M   M::::::M  P::::P            \
"

#define PYSAMP_LOADING_SCREEN_3 \
"\
  P::::P                  y:::::y:::::y                  S:::::S   A:::::::::::::::::::::A     M::::::M    M:::::M    M::::::M  P::::P            \n\
             P::::P                   y:::::::::y                   S:::::S  A:::::AAAAAAAAAAAAA:::::A    M::::::M     MMMMM     M::::::M  P::::P            \n\
           PP::::::PP                  y:::::::y        SSSSSSS     S:::::S A:::::A             A:::::A   M::::::M               M::::::MPP::::::PP          \n\
           P::::::::P                   y:::::y         S::::::SSSSSS:::::SA:::::A               A:::::A  M::::::M               M::::::MP::::::::P          \n\
           P::::::::P                  y:::::y          S:::::::::::::::SSA:::::A                 A:::::A M::::::M               M::::::MP::::::::P          \
"

#define PYSAMP_LOADING_SCREEN_4 \
"\
PPPPPPPPPP                 y:::::y            SSSSSSSSSSSSSSS AAAAAAA                   AAAAAAAMMMMMMMM               MMMMMMMMPPPPPPPPPP          \n\
                                     y:::::y                                                                                                                 \n\
                                    y:::::y                                                                                                                  \n\
                                   y:::::y                                                                                                                   \n\
                                  y:::::y                                                                                                                    \n\
                                 yyyyyyy                                                                                                                     \
"

#endif
