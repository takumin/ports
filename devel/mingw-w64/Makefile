# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	mingw-w64
PORTVERSION=	4.0.1
CATEGORIES=	devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-release
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER=	takumiiinn@gmail.com
COMMENT?=	MinGW-w64 for runtime and w32api

USES=		tar:bzip2 gmake
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.ifndef CROSS_TARGET
IGNORE=		build for 'devel/mingw32-crt' or 'devel/mingw64-crt'
.endif

CONFIGURE_ARGS+=--host=${CROSS_HOST}

.include <bsd.port.post.mk>
