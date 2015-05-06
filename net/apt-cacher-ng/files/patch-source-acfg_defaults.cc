--- ./source/acfg_defaults.cc.orig	2015-05-06 11:31:35.359177000 +0900
+++ ./source/acfg_defaults.cc	2015-05-06 11:52:30.405728000 +0900
@@ -13,7 +13,7 @@
 
 string cachedir("/var/tmp"), logdir("/var/tmp"), fifopath, pidfile, reportpage,
 confdir, adminauth, bindaddr, mirrorsrcs, suppdir("/usr/lib/apt-cacher-ng"),
-capath("/etc/ssl/certs"), cafile, badredmime("text/html");
+capath("/usr/local/share/certs"), cafile, badredmime("text/html");
 
 #define INFOLDER "(^|.*/)"
 #define COMPRLIST "(\\.gz|\\.bz2|\\.lzma|\\.xz)"
@@ -24,7 +24,7 @@
 
 string spfilepat(INFOLDER ".*(\\.d?deb|\\.rpm|\\.drpm|\\.dsc|\\.tar" COMPRLIST ")\\.gpg$");
 
-string pfilepat(".*(\\.d?deb|\\.rpm|\\.drpm|\\.dsc|\\.tar" COMPRLIST
+string pfilepat(".*(\\.d?deb|\\.rpm|\\.drpm|\\.dsc|\\.tar|\\.txz" COMPRLIST
 		"|\\.diff" COMPRLIST "|\\.jigdo|\\.template|changelog|copyright"
 		"|\\.udeb|\\.debdelta|\\.diff/.*\\.gz|(Devel)?ReleaseAnnouncement(\\?.*)?"
 		"|[a-f0-9]+-(susedata|updateinfo|primary|deltainfo).xml.gz" //opensuse, index data, hash in filename
@@ -47,6 +47,7 @@
 		"|" ALXPATTERN // Arch Linux
 		"|metalink\\?repo|.*prestodelta\\.xml\\.gz|repodata/.*\\.(xml|sqlite)" COMPOPT // CentOS
 		"|\\.treeinfo|vmlinuz|(initrd|product|squashfs|updates)\\.img" // Fedora
+		"|(meta|packagesite|digests)\\.txz" // FreeBSD pkgng
 		"|\\.o" // https://bugs.launchpad.net/ubuntu/+source/apt-cacher-ng/+bug/1078224
 		")$" // end of only-filename paterns
 		"|/dists/.*/installer-[^/]+/[^0-9][^/]+/images/.*" // d-i stuff but not containing a date (year number) in the revision directory (like "current", "beta", ...)
