--- source/apt-cacher.cc.orig	2016-01-24 08:32:43 UTC
+++ source/apt-cacher.cc
@@ -5,6 +5,7 @@
 #include <stddef.h>
 #include <sys/stat.h>
 #include <sys/types.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include <cstdbool>
 #include <cstdint>
