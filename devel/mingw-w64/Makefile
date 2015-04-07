# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME?=		mingw-w64
PKGNAMESUFFIX?=		-crt
PORTVERSION=		4.0.1
CATEGORIES=		devel
MASTER_SITES=		SF
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}/${PORTNAME}-release
DISTNAME=		${PORTNAME}-v${PORTVERSION}

MAINTAINER=		takumiiinn@gmail.com
COMMENT?=		MinGW-w64 for runtime and w32api

USES=			tar:bzip2 gmake
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-sysroot=/

.if !defined(MINGW64_HEADER)
BUILD_DEPENDS+=		${LOCALBASE}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-header
CONFIGURE_ARGS+=	--with-tools=all \
			--without-headers
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=	--host=x86_64-w64-mingw32 \
			--build=x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_ARGS+=	--host=${ARCH}-w64-mingw32 \
			--build=${ARCH}-portbld-freebsd${OSREL}
.endif

.include <bsd.port.post.mk>
