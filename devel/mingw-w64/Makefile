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

.ifndef PKGNAMESUFFIX
IGNORE=		build for 'devel/mingw32-crt' or 'devel/mingw64-crt'
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

WRKSRC_SUBDIR=	${PORTNAME}${PKGNAMESUFFIX:C/-(i686|x86_64)//}

CONFIGURE_ARGS+=--host=${PKGNAMESUFFIX:C/-(headers|crt)//}-w64-mingw32

.include <bsd.port.post.mk>
