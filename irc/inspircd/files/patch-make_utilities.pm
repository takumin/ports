--- make/utilities.pm.orig	2016-01-24 08:48:56 UTC
+++ make/utilities.pm
@@ -29,6 +29,7 @@ use warnings FATAL => qw(all);
 
 use Exporter 'import';
 use POSIX;
+use File::Temp;
 use Getopt::Long;
 use Fcntl;
 our @EXPORT = qw(make_rpath pkgconfig_get_include_dirs pkgconfig_get_lib_dirs pkgconfig_check_version translate_functions promptstring);
@@ -401,10 +402,11 @@ sub translate_functions($$)
 		while ($line =~ /eval\("(.+?)"\)/)
 		{
 			print "Evaluating perl code for module \e[1;32m$module\e[0m ... ";
-			my $tmpfile;
+			my $tmpfile, $tmpfh;
 			do
 			{
-				$tmpfile = tmpnam();
+				($tmpfile, $tmpfh) = tempfile();
+				close $tmpfh;
 			} until sysopen(TF, $tmpfile, O_RDWR|O_CREAT|O_EXCL|O_NOFOLLOW, 0700);
 			print "(Created and executed \e[1;32m$tmpfile\e[0m)\n";
 			print TF $1;
