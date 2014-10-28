# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	forked-daapd
PORTVERSION=	22.0
CATEGORIES=	audio

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	forked-daapd is a Linux/FreeBSD DAAP (iTunes) and RSP (Roku) media server.

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ejurgensen
GH_COMMIT=	61a4da2
WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${PORTNAME}-fc0a2e9

USES=		autoreconf gettext gmake gperf iconv libtool
BUILD_DEPENDS=	antlr:${PORTSDIR}/devel/antlr
LIB_DEPENDS=	libantlr3c.so:${PORTSDIR}/devel/libantlr3c \
		libavahi-client.so:${PORTSDIR}/net/avahi-app \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libavcodec.so:${PORTSDIR}/multimedia/libav \
		libconfuse.so:${PORTSDIR}/devel/libconfuse \
		libevent.so:${PORTSDIR}/devel/libevent2 \
		libavl.so:${PORTSDIR}/devel/libavl-debian \
		libmxml.so:${PORTSDIR}/textproc/mxml \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libunistring.so:${PORTSDIR}/devel/libunistring

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=${ICONV_CONFIGURE_ARG} \
		--with-libunistring-prefix=${LOCALBASE}

.include <bsd.port.pre.mk>

port-patch:
	@${REINPLACE_CMD} -e 's@[antlr3]@[antlr]@g' ${WRKSRC}/configure.ac

.include <bsd.port.post.mk>
