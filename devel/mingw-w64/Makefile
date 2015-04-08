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
IGNORE=		build for 'devel/mingw-w64-i686-crt' or 'devel/mingw-w64-x86_64-crt'
.endif

BUILD_ARCH=	${PKGNAMESUFFIX:C/^-(.*)-(.*)$/\1/}
BUILD_TYPE=	${PKGNAMESUFFIX:C/^-(.*)-(.*)$/\2/}
TARGET_ARCH=	${BUILD_ARCH}-w64-mingw32

WRKSRC_SUBDIR=	${PORTNAME}-${BUILD_TYPE}
GNU_CONFIGURE_PREFIX=	${PREFIX}/${TARGET_ARCH}

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

CONFIGURE_ARGS+=--host=${TARGET_ARCH}

.if ${BUILD_TYPE} == "headers"
CONFIGURE_ARGS+=--enable-sdk=all --enable-secure-api
.endif

PLIST_SUB=	TARGET_ARCH=${TARGET_ARCH}

.include <bsd.port.post.mk>
