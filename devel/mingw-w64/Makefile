# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	mingw-w64
PORTVERSION=	4.0.1
CATEGORIES=	devel
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-release
DISTNAME=	${PORTNAME}-v${PORTVERSION}

MAINTAINER?=	takumiiinn@gmail.com
COMMENT?=	MinGW-w64 for headers and runtime

USES=		tar:bzip2 gmake
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.ifndef PKGNAMESUFFIX
IGNORE=		build for 'devel/mingw-w64-i686-crt' or 'devel/mingw-w64-x86_64-crt'
.endif

BUILD_ARCH=	${PKGNAMESUFFIX:C/^-(.*)-(.*)$/\1/}
BUILD_TYPE=	${PKGNAMESUFFIX:C/^-(.*)-(.*)$/\2/}
TARGET_ARCH=	${BUILD_ARCH}-w64-mingw32
GCC_SUFFIX!=	${MAKE} -V SUFFIX -C ../${PORTNAME}-${BUILD_ARCH}-gcc-core

WRKSRC_SUBDIR=	${PORTNAME}-${BUILD_TYPE}

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

CC=		${TARGET_ARCH}-gcc${GCC_SUFFIX}
CPP=		${TARGET_ARCH}-g++${GCC_SUFFIX}
CXX=		${TARGET_ARCH}-gcc${GCC_SUFFIX} -E
CONFIGURE_ARGS+=--host=${TARGET_ARCH}

.if ${BUILD_TYPE} == "headers"
GNU_CONFIGURE_PREFIX=	${PREFIX}/${TARGET_ARCH}
CONFIGURE_ARGS+=--enable-sdk=all --enable-secure-api
.elif ${BUILD_TYPE} == "crt"
BUILD_DEPENDS+=	${LOCALBASE}/${TARGET_ARCH}/include/_mingw.h:${PORTSDIR}/devel/${PORTNAME}-${BUILD_ARCH}-headers \
		${LOCALBASE}/bin/${TARGET_ARCH}-as:${PORTSDIR}/devel/${PORTNAME}-${BUILD_ARCH}-binutils \
		${LOCALBASE}/bin/${TARGET_ARCH}-gcc:${PORTSDIR}/devel/${PORTNAME}-${BUILD_ARCH}-gcc-core
CFLAGS+=	-I${LOCALBASE}/${TARGET_ARCH}/include
CONFIGURE_ARGS+=--enable-wildcard
. if ${BUILD_ARCH} == "i686"
CONFIGURE_ARGS+=--disable-lib64 --enable-lib32
. elif ${BUILD_ARCH} == "x86_64"
CONFIGURE_ARGS+=--disable-lib32 --enable-lib64
. endif
.endif

PLIST_SUB=	TARGET_ARCH=${TARGET_ARCH}

.include <bsd.port.post.mk>
