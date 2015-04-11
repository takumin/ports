# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	pthreads
PORTVERSION=	2.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEWARE}
MASTER_SITE_SUBDIR=	${PORTNAME}-win32
DISTNAME=	${PORTNAME}-w32-${PORTVERSION:S/./-/g}-release

MAINTAINER?=	takumiiinn@gmail.com
COMMENT?=	POSIX threads library for Windows compiled with MinGW-w64

LICENSE=	LGPL21

.ifndef PKGNAMEPREFIX
IGNORE=		build for 'devel/mingw-w64-i686-pthreads' or 'devel/mingw-w64-x86_64-pthreads'
.else
CROSS_ARCH=	${PKGNAMEPREFIX:C/^mingw-w64-(.*)-$/\1/}
CROSS_TARGET=	${CROSS_ARCH}-w64-mingw32
. if ! ( ${CROSS_ARCH} == "i686" || ${CROSS_ARCH} == "x86_64" )
IGNORE=		support target for "i686-w64-mingw32" or "x86_64-w64-mingw32"
. endif
.endif

USES=		gmake
BUILD_DEPENDS+=	${CROSS_TARGET}-gcc:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-gcc

MAKEFILE=	${WRKSRC}/GNUmakefile
MAKE_ARGS=	CROSS='${CROSS_TARGET}-'
ALL_TARGET=	GC

PLIST_SUB=	CROSS_TARGET=${CROSS_TARGET}

.include <bsd.port.pre.mk>

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/include
.for f in pthread.h sched.h semaphore.h
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/include/$f
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/lib
.for f in libpthreadGC2.a pthreadGC2.dll
	${INSTALL_DATA} ${WRKSRC}/$f ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/lib/$f
.endfor
	${LN} -sf libpthreadGC2.a ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/lib/libpthread.a

.include <bsd.port.post.mk>
