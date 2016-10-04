--- include/acbuf.h.orig	2016-10-04 02:13:02 UTC
+++ include/acbuf.h
@@ -52,14 +52,14 @@ class acbuf
          * \param maxlen Maximum amount of data to write
          * \return Number of written bytes, negative on failures, see write(2)
          */
-        int syswrite(int fd, unsigned int maxlen=MAX_VAL(uint));
+        int syswrite(int fd, unsigned int maxlen=MAX_VAL(unsigned int));
 
         /*
          * Reads from a file descriptor and append to buffered data, update position indexes.
          * \param fd File descriptor
          * \return Number of read bytes, negative on failures, see read(2)
          */
-        int sysread(int fd, unsigned int maxlen=MAX_VAL(uint));
+        int sysread(int fd, unsigned int maxlen=MAX_VAL(unsigned int));
 
 
     protected:
