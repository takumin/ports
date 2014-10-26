# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	libavl
PKGNAMESUFFIX=	-debian
PORTVERSION=	0.3.5
PORTREVISION=	3
CATEGORIES=	devel

MASTER_SITES=	http://ftp.debian.org/debian/pool/main/liba/libavl/

DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.orig.tar.gz

WRKSRC=		${WRKDIR}/avl-${PORTVERSION}

MAKEFILE=	GNUmakefile
MAKE_ENV=	DESTDIR=${STAGEDIR}
ALL_TARGET=	install

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	${DISTNAME}-${PORTREVISION}.diff.gz
PATCH_DIST_STRIP=-p1

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	forked-daapd libavl

USES=		gmake

.include <bsd.port.pre.mk>
.include <bsd.port.post.mk>
