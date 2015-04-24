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
GH_TAGNAME=	072810c4aa7dbc30f01f9bf5ae3665e580c1d406

USES+=		autoreconf compiler gettext gmake gperf iconv libtool pathfix pkgconfig
BUILD_DEPENDS+=	antlr34:${PORTSDIR}/devel/antlr34
LIB_DEPENDS+=	libantlr3c.so:${PORTSDIR}/devel/libantlr3c \
		libavahi-client.so:${PORTSDIR}/net/avahi-app \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libavcodec.so:${PORTSDIR}/multimedia/ffmpeg \
		libconfuse.so:${PORTSDIR}/devel/libconfuse \
		libevent.so:${PORTSDIR}/devel/libevent2 \
		libmxml.so:${PORTSDIR}/textproc/mxml \
		libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libunistring.so:${PORTSDIR}/devel/libunistring

OPTIONS_DEFINE=	OSS ALSA FLAC MUSEPACK ITUNES LASTFM MPD
OPTIONS_DEFAULT=ALSA FLAC MUSEPACK ITUNES LASTFM MPD

OPTIONS_SINGLE=	AUDIO
OPTIONS_SINGLE_AUDIO=	OSS ALSA

ITUNES_DESC=	iTunes XML support
LASTFM_DESC=	LastFM support
MPD_DESC=	MPD protocol support

OSS_CONFIGURE_WITH=	oss4
ALSA_CONFIGURE_WITH=	alsa
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/alsa-lib
FLAC_CONFIGURE_ENABLE=	flac
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
MUSEPACK_CONFIGURE_ENABLE=musepack
MUSEPACK_LIB_DEPENDS=	libtag_c.so:${PORTSDIR}/audio/taglib
ITUNES_CONFIGURE_ENABLE=itunes
ITUNES_LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist
LASTFM_CONFIGURE_ENABLE=lastfm
LASTFM_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
MPD_CONFIGURE_ENABLE=	mpd

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USERS=		daapd
GROUPS=		daapd

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
CONFIGURE_ENV+=	ANTLR="${LOCALBASE}/bin/antlr34"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_RC_SUBR=	forked_daapd

.include <bsd.port.pre.mk>

post-patch:
	# antlr3AsciiFileStreamNew() for old function.
	# see http://www.antlr3.org/pipermail/antlr-interest/2011-June/041924.html
	${REINPLACE_CMD} -e 's@antlr3AsciiFileStreamNew((pANTLR3_UINT8) file)@antlr3FileStreamNew((pANTLR3_UINT8) file, ANTLR3_ENC_8BIT)@' ${WRKSRC}/src/filescanner_smartpl.c

post-install:
	# pkg-plist for @sample etc/forked-daapd.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/forked-daapd.conf ${STAGEDIR}${PREFIX}/etc/forked-daapd.conf.sample
	# pkg-plist for @dir(daapd,daapd,700) /var/cache/forked-daapd/libspotify
	# pkg-plist for @dir(daapd,daapd,700) /var/cache/forked-daapd
	# pkg-plist for other `make makeplist`

.include <bsd.port.post.mk>
