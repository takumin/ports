# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	forked-daapd
PORTVERSION=	22.1
CATEGORIES=	audio

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	DAAP (iTunes) and RSP (Roku) media server

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ejurgensen
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	6489d71
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-10f321c

USES+=		autoreconf gettext gmake gperf iconv libtool
BUILD_DEPENDS+=	antlr3:${PORTSDIR}/devel/antlr3 \
		${LOCALBASE}/lib/oss/include/sys/soundcard.h:${PORTSDIR}/audio/oss
LIB_DEPENDS+=	libantlr3c.so:${PORTSDIR}/devel/libantlr3c \
		libavahi-client.so:${PORTSDIR}/net/avahi-app \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libavcodec.so:${PORTSDIR}/multimedia/libav \
		libconfuse.so:${PORTSDIR}/devel/libconfuse \
		libevent.so:${PORTSDIR}/devel/libevent2 \
		libavl.so:${PORTSDIR}/devel/libavl-debian \
		libmxml.so:${PORTSDIR}/textproc/mxml \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libunistring.so:${PORTSDIR}/devel/libunistring

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	"-I${LOCALBASE}/include"
CFLAGS+=	"-I/usr/include"
CPPFLAGS+=	"-I${LOCALBASE}/include"
CPPFLAGS+=	"-I/usr/include"
LDFLAGS+=	"-L${LOCALBASE}/lib"
LIBUNISTRING_CFLAGS=	"-I/usr/include"
LIBUNISTRING_LIBS=	"-L/usr/lib"
ZLIB_CFLAGS=		"-I/usr/include"
ZLIB_LIBS=		"-L/usr/lib"

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
