# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	fuppes
PORTVERSION=	2014.01.22
CATEGORIES=	multimedia

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Free UPnP A/V Media Server

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	u-voelkel
GH_TAGNAME=	1c9b4cc78e2dd3f424face74d06ac3918ea38180

USES=		autoreconf compiler gettext gmake iconv:wchar_t libtool pathfix pkgconfig
USE_GCC=	yes
LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libxml2.so:textproc/libxml2 \
		libsqlite3.so:databases/sqlite3 \
		libev.so:devel/libev \
		libuuid.so:misc/e2fsprogs-libuuid

# TODO: fix inotify
#OPTIONS_DEFINE+=		INOTIFY
#INOTIFY_DESC=			libinotify support
#INOTIFY_LIB_DEPENDS=		libinotify.so:devel/libinotify
#INOTIFY_CONFIGURE_ENABLE=	inotify

USERS=		dlna
GROUPS=		dlna

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

post-stage:
	@${MV} ${STAGEDIR}/var/lib/fuppes ${STAGEDIR}${ETCDIR}
	@${RMDIR} ${STAGEDIR}/var/lib
	@${RMDIR} ${STAGEDIR}/var

.include <bsd.port.mk>
