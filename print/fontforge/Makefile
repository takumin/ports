# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	fontforge
PORTVERSION=	${RELEASEDATE:S/-//g}
RELEASEDATE=	2014-11-26
CATEGORIES=	print
MASTER_SITES=	https://github.com/fontforge/fontforge/releases/download/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${RELEASEDATE}-Unix-Source

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Type 1/TrueType/OpenType/bitmap font editor

LICENSE=	GPLv3

GNOME=		glib20 pango
USES+=		autoreconf gettext gmake iconv libtool pkgconfig python
LIB_DEPENDS+=	libuninameslist.so:${PORTSDIR}/textproc/libuninameslist \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libxml2.so:${PORTSDIR}/textproc/libxml2 \
		libspiro.so:${PORTSDIR}/graphics/libspiro \
		libfreetype.so:${PORTSDIR}/print/freetype2

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
LDFLAGS+=	-lutil

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-pyextensio --enable-extra-encodings

.include <bsd.port.pre.mk>

pre-configure:
	@cd ${WRKSRC} && ./bootstrap

.include <bsd.port.post.mk>
