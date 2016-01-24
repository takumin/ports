--- test/build/HAVE_DAEMON.cc.orig	2016-01-24 08:33:39 UTC
+++ test/build/HAVE_DAEMON.cc
@@ -1,3 +1,4 @@
 
 #include <unistd.h>
+#include <stdlib.h>
 int main() { return daemon(0, 0); }
