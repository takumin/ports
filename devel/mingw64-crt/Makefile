# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=		mingw64
PKGNAMESUFFIX?=		-crt
PORTVERSION=		4.0.1
CATEGORIES=		devel
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	mingw-w64/mingw-w64/mingw-w64-release
DISTNAME=		mingw-w64-v${PORTVERSION}

MAINTAINER=		takumiiinn@gmail.com
COMMENT?=		MinGW-w64 for runtime and w32api

USES=			tar:bzip2 gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/x86_64-w64-mingw32

.include <bsd.port.pre.mk>

.if ${PKGNAMESUFFIX} == "-crt"
BUILD_DEPENDS+=		${LOCALBASE}/x86_64-w64-mingw32/include/_mingw.h:${PORTSDIR}/devel/mingw64-header \
			x86_64-w64-mingw32-gcc:${PORTSDIR}/devel/mingw64-gcc-core
CC=			x86_64-w64-mingw32-gcc
CXX=			x86_64-w64-mingw32-c++
CPP=			x86_64-w64-mingw32-cpp
AR=			x86_64-w64-mingw32-ar
RANLIB=			x86_64-w64-mingw32-ranlib
WRKSRC_SUBDIR=		mingw-w64-crt
.else
WRKSRC_SUBDIR=		mingw-w64-headers
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--host=x86_64-w64-mingw32
.else
CONFIGURE_ARGS+=	--host=${ARCH}-w64-mingw32
.endif

post-stage:
.if ${PKGNAMESUFFIX} == "-crt"
	@${LN} -sf lib ${STAGEDIR}${PREFIX}/x86_64-w64-mingw32/lib64
.else
	@${LN} -sf x86_64-w64-mingw32 ${STAGEDIR}${PREFIX}/x86_64-w64-mingw32/mingw
.endif

.include <bsd.port.post.mk>
