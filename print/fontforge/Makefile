# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	fontforge
PORTVERSION=	${RELEASEDATE:S/-//g}
RELEASEDATE=	2014-11-26
CATEGORIES=	print
MASTER_SITES=	https://github.com/fontforge/fontforge/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${RELEASEDATE}-Unix-Source
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LICENSE=	GPLv3

USES+=		autoreconf gettext gmake iconv libtool pkgconfig python
BUILD_DEPENDS+=	git:${PORTSDIR}/devel/git
LIB_DEPENDS+=	libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libpango-1.0.so:${PORTSDIR}/x11-toolkits/pango \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libspiro.so:${PORTSDIR}/graphics/libspiro \
		libzmq.so:${PORTSDIR}/net/libzmq4 \
		libuninameslist.so:${PORTSDIR}/textproc/libuninameslist \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libfreetype.so:${PORTSDIR}/print/freetype2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
#LDFLAGS+=	-lutil
#LDFLAGS+=	-lintl
ZLIB_CFLAGS=	-I/usr/include
ZLIB_LIBS=	-L/usr/lib -lz

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--without-x

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC} && ./bootstrap --gnulib-srcdir=gnulib --skip-git --skip-po --force

.include <bsd.port.post.mk>
