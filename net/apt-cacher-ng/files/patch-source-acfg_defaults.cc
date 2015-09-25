--- source/acfg_defaults.cc.orig	2015-09-21 20:05:55 UTC
+++ source/acfg_defaults.cc
@@ -13,7 +13,7 @@ namespace acfg
 
 string cachedir("/var/tmp"), logdir("/var/tmp"), fifopath, pidfile, reportpage,
 confdir, adminauth, adminauthB64, bindaddr, mirrorsrcs, suppdir(LIBDIR),
-capath("/etc/ssl/certs"), cafile, badredmime("text/html");
+capath("/usr/local/share/certs"), cafile, badredmime("text/html");
 
 #define INFOLDER "(^|.*/)"
 #define COMPRLIST "(\\.gz|\\.bz2|\\.lzma|\\.xz)"
@@ -30,6 +30,7 @@ string pfilepat(".*(\\.(u|d)?deb|\\.rpm|
 		"|[a-f0-9]+-(susedata|updateinfo|primary|deltainfo).xml.gz" //opensuse, index data, hash in filename
 		"|fonts/(final/)?[a-z]+32.exe(\\?download.*)?" // msttcorefonts, fonts/final/comic32.exe /corefonts/comic32.exe plus SF's parameters
 		"|/dists/.*/installer-[^/]+/[0-9][^/]+/images/.*" // d-i stuff with revision
+		"|/(All|Latest)/[^/]+\\.txz(\\.sig)?" // FreeBSD pkgng
 ")$");
 
 string svfilepat("/development/rawhide/.*");
@@ -44,6 +45,7 @@ string vfilepat(INFOLDER
 		"|products|content(\\.asc|\\.key)?|media" // opensuse 2, are they important?
 		"|filelists\\.xml\\.gz|filelists\\.sqlite\\.bz2|repomd\\.xml" // SL, http://ra.khe.sh/computers/linux/apt-cacher-ng-with-yum.html
 		"|packages\\.[a-zA-Z][a-zA-Z]\\.gz|info\\.txt|license\\.tar\\.gz|license\\.zip" //opensuse
+		"|(meta|packagesite|digests)\\.txz" // FreeBSD pkgng
 		"|" ALXPATTERN // Arch Linux
 		"|metalink\\?repo|.*prestodelta\\.xml\\.gz|repodata/.*\\.(xml|sqlite)" COMPOPT // CentOS
 		"|\\.treeinfo|vmlinuz|(initrd|product|squashfs|updates)\\.img" // Fedora
