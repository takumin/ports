--- ./test/build/HAVE_DAEMON.cc.orig	2015-05-05 09:58:32.357273000 +0900
+++ ./test/build/HAVE_DAEMON.cc	2015-05-05 09:58:53.032465000 +0900
@@ -1,3 +1,3 @@
 
-#include <unistd.h>
+#include <stdlib.h>
 int main() { return daemon(0, 0); }
