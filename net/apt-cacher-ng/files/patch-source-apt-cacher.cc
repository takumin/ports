--- ./source/apt-cacher.cc.orig	2015-05-05 10:51:41.879347000 +0900
+++ ./source/apt-cacher.cc	2015-05-05 10:53:46.310478000 +0900
@@ -6,6 +6,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <stdlib.h>
 #include <cstdbool>
 #include <cstdint>
 #include <cstdlib>
