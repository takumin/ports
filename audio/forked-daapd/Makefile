# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	forked-daapd
PORTVERSION=	23.3
CATEGORIES=	audio

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	DAAP (iTunes) and RSP (Roku) media server

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ejurgensen

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

OPTIONS_DEFINE=	FLAC MUSEPACK ITUNES LASTFM MPD

OPTIONS_RADIO=	AUDIO
OPTIONS_RADIO_AUDIO=	OSS ALSA

OPTIONS_DEFAULT=FLAC MUSEPACK ITUNES LASTFM MPD OSS

ITUNES_DESC=	iTunes XML support
LASTFM_DESC=	LastFM support
MPD_DESC=	MPD protocol support

OSS_CONFIGURE_WITH=	oss4
ALSA_CONFIGURE_WITH=	alsa
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
FLAC_CONFIGURE_ENABLE=	flac
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
MUSEPACK_CONFIGURE_ENABLE=musepack
MUSEPACK_LIB_DEPENDS=	libtag_c.so:${PORTSDIR}/audio/taglib
ITUNES_CONFIGURE_ENABLE=itunes
ITUNES_LIB_DEPENDS=	libplist.so:${PORTSDIR}/devel/libplist
LASTFM_CONFIGURE_ENABLE=lastfm
LASTFM_LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
MPD_CONFIGURE_ENABLE=	mpd

USERS=		daapd
GROUPS=		daapd

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=${ARCH:S/amd64/x86_64/}-portbld-${OPSYS:tl}${OSREL}
CONFIGURE_ENV+=	ANTLR="${LOCALBASE}/bin/antlr34"
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	${LOCALBASE}/lib/forked-daapd
USE_RC_SUBR=	forked_daapd

.include <bsd.port.pre.mk>

post-patch:
	# respect hier(7)
	# pkg-plist for @dir(daapd,daapd,700) /var/cache/forked-daapd/libspotify
	# pkg-plist for @dir(daapd,daapd,700) /var/cache/forked-daapd
	@${REINPLACE_CMD} -e 's@$$(DESTDIR)$$(localstatedir)@${STAGEDIR}/var@' ${WRKSRC}/Makefile.am

post-install:
	# pkg-plist for @sample etc/forked-daapd.conf.sample
	@${MV} ${STAGEDIR}${PREFIX}/etc/forked-daapd.conf ${STAGEDIR}${PREFIX}/etc/forked-daapd.conf.sample
	# pkg-plist for other `make makeplist`

.include <bsd.port.post.mk>
