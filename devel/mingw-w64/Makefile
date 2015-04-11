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

.ifndef PKGNAMESUFFIX
IGNORE=		build for 'devel/mingw-w64-i686-crt' or 'devel/mingw-w64-x86_64-crt'
.else
CROSS_ARCH=	${PKGNAMESUFFIX:C/^-(.*)-(.*)$/\1/}
BUILD_TYPE=	${PKGNAMESUFFIX:C/^-(.*)-(.*)$/\2/}
CROSS_TARGET=	${CROSS_ARCH}-w64-mingw32
. if ! ( ${CROSS_ARCH} == "i686" || ${CROSS_ARCH} == "x86_64" )
IGNORE=		support target for "i686-w64-mingw32" or "x86_64-w64-mingw32"
. endif
.endif

USES=		gmake libtool tar:bzip2
GNU_CONFIGURE=	yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/${CROSS_TARGET}
CONFIGURE_ARGS+=--host=${CROSS_TARGET}
SSP_UNSAFE=	yes
PLIST=		${.CURDIR}/../mingw-w64/pkg-plist.${BUILD_TYPE}
PLIST_SUB=	CROSS_TARGET=${CROSS_TARGET}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

.ifdef PKGNAMESUFFIX
.if ${BUILD_TYPE} == "pthreads"
WRKSRC_SUBDIR=	${PORTNAME}-libraries/win${BUILD_TYPE}
.else
WRKSRC_SUBDIR=	${PORTNAME}-${BUILD_TYPE}
.endif

. if ${BUILD_TYPE} == "crt" || ${BUILD_TYPE} == "pthreads"
CC:=		${CROSS_TARGET}-gcc-bootstrap
CPP:=		${CROSS_TARGET}-cpp-bootstrap
CXX:=		${CROSS_TARGET}-g++-bootstrap
BUILD_DEPENDS+=	${CROSS_TARGET}-as:${PORTSDIR}/devel/${PORTNAME}-${CROSS_ARCH}-binutils \
		${CROSS_TARGET}-gcc-bootstrap:${PORTSDIR}/devel/${PORTNAME}-${CROSS_ARCH}-gcc-bootstrap \
		${LOCALBASE}/${CROSS_TARGET}/include/_mingw.h:${PORTSDIR}/devel/${PORTNAME}-${CROSS_ARCH}-headers
.  if ${BUILD_TYPE} == "pthreads"
BUILD_DEPENDS+=	${LOCALBASE}/${CROSS_TARGET}/lib/libmingw32.a:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-crt
.  endif
. endif

. if ${BUILD_TYPE} == "headers"
CONFIGURE_ARGS+=--enable-sdk=all --enable-secure-api
. elif ${BUILD_TYPE} == "crt"
CONFIGURE_ARGS+=--enable-wildcard
.  if ${CROSS_ARCH} == "i686"
CONFIGURE_ARGS+=--disable-lib64 --enable-lib32
.  elif ${CROSS_ARCH} == "x86_64"
CONFIGURE_ARGS+=--disable-lib32 --enable-lib64
.  endif
. endif

. if ${BUILD_TYPE} == "headers"
post-stage:
	${RM} ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/include/pthread_signal.h
	${RM} ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/include/pthread_time.h
	${RM} ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/include/pthread_unistd.h
. elif ${BUILD_TYPE} == "crt"
pre-configure:
	${ECHO_CMD} '/* Dummy header */' > ${LOCALBASE}/${CROSS_TARGET}/include/pthread_signal.h
	${ECHO_CMD} '/* Dummy header */' > ${LOCALBASE}/${CROSS_TARGET}/include/pthread_time.h
	${ECHO_CMD} '/* Dummy header */' > ${LOCALBASE}/${CROSS_TARGET}/include/pthread_unistd.h
post-install:
	${RM} ${LOCALBASE}/${CROSS_TARGET}/include/pthread_signal.h
	${RM} ${LOCALBASE}/${CROSS_TARGET}/include/pthread_time.h
	${RM} ${LOCALBASE}/${CROSS_TARGET}/include/pthread_unistd.h
. elif ${BUILD_TYPE} == "pthreads"
post-configure:
	${REINPLACE_CMD} -e 's@^RCFLAGS.*$$@RCFLAGS = --preprocessor=${CROSS_TARGET}-cpp-bootstrap@' ${WRKSRC}/Makefile
. endif
.endif

.include <bsd.port.post.mk>
