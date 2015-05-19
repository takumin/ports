--- source/acfg_defaults.cc.orig	2015-05-03 00:19:23.000000000 +0900
+++ source/acfg_defaults.cc	2015-05-20 02:49:38.133755000 +0900
@@ -13,7 +13,7 @@
 
 string cachedir("/var/tmp"), logdir("/var/tmp"), fifopath, pidfile, reportpage,
 confdir, adminauth, bindaddr, mirrorsrcs, suppdir("/usr/lib/apt-cacher-ng"),
-capath("/etc/ssl/certs"), cafile, badredmime("text/html");
+capath("/usr/local/share/certs"), cafile, badredmime("text/html");
 
 #define INFOLDER "(^|.*/)"
 #define COMPRLIST "(\\.gz|\\.bz2|\\.lzma|\\.xz)"
@@ -30,6 +30,7 @@
 		"|[a-f0-9]+-(susedata|updateinfo|primary|deltainfo).xml.gz" //opensuse, index data, hash in filename
 		"|fonts/(final/)?[a-z]+32.exe(\\?download.*)?" // msttcorefonts, fonts/final/comic32.exe /corefonts/comic32.exe plus SF's parameters
 		"|/dists/.*/installer-[^/]+/[0-9][^/]+/images/.*" // d-i stuff with revision
+		"|/(All|Latest)/[0-9a-zA-Z-_\\.]+\\.txz(\\.sig)?" // FreeBSD pkgng
 ")$");
 
 string svfilepat("/development/rawhide/.*");
@@ -47,6 +48,7 @@
 		"|" ALXPATTERN // Arch Linux
 		"|metalink\\?repo|.*prestodelta\\.xml\\.gz|repodata/.*\\.(xml|sqlite)" COMPOPT // CentOS
 		"|\\.treeinfo|vmlinuz|(initrd|product|squashfs|updates)\\.img" // Fedora
+		"|(meta|packagesite|digests)\\.txz" // FreeBSD pkgng
 		"|\\.o" // https://bugs.launchpad.net/ubuntu/+source/apt-cacher-ng/+bug/1078224
 		")$" // end of only-filename paterns
 		"|/dists/.*/installer-[^/]+/[^0-9][^/]+/images/.*" // d-i stuff but not containing a date (year number) in the revision directory (like "current", "beta", ...)
