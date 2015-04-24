# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	forked-daapd
PORTVERSION=	22.3
CATEGORIES=	audio
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	DAAP (iTunes) and RSP (Roku) media server

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ejurgensen
GH_TAGNAME=	0e1de8e0bbce728748e7ed9de1f3e4346a3b1dce

USES+=		autoreconf compiler gettext gmake gperf iconv libtool pathfix pkgconfig
BUILD_DEPENDS+=	antlr3:${PORTSDIR}/devel/antlr3
LIB_DEPENDS+=	libantlr3c.so:${PORTSDIR}/devel/libantlr3c \
		libavahi-client.so:${PORTSDIR}/net/avahi-app \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libconfuse.so:${PORTSDIR}/devel/libconfuse \
		libevent.so:${PORTSDIR}/devel/libevent2 \
		libmxml.so:${PORTSDIR}/textproc/mxml \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libunistring.so:${PORTSDIR}/devel/libunistring

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		daapd
GROUPS=		daapd

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
CONFIGURE_ARGS+=CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_RC_SUBR=	forked_daapd

.include <bsd.port.pre.mk>

post-patch:
	# http://www.antlr3.org/pipermail/antlr-interest/2011-June/041924.html
	# antlr3AsciiFileStreamNew() for old function.
	${REINPLACE_CMD} -e 's@antlr3AsciiFileStreamNew((pANTLR3_UINT8) file)@antlr3FileStreamNew((pANTLR3_UINT8) file, ANTLR3_ENC_8BIT)@' ${WRKSRC}/src/filescanner_smartpl.c

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf ${STAGEDIR}${PREFIX}/etc/${PORTNAME}.conf.sample
	${CHMOD} -R 0700 ${STAGEDIR}/var/cache/${PORTNAME}
	${CHOWN} -R 337:337 ${STAGEDIR}/var/cache/${PORTNAME}

.include <bsd.port.post.mk>
