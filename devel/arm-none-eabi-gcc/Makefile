# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	5.2.0
PORTREVISION?=	1
CATEGORIES=	devel
MASTER_SITES=	GCC
PKGNAMEPREFIX=	arm-none-eabi-

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Cross GNU Compiler Collection for ${GCC_TARGET}

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

USES=		compiler cpe gmake iconv libtool makeinfo tar:bzip2
USE_PERL5=	build

LIB_DEPENDS+=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc
BUILD_DEPENDS+=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils
.ifndef PKGNAMESUFFIX
BUILD_DEPENDS+=	${PKGNAMEPREFIX}${PORTNAME}-bootstrap:${PORTSDIR}/devel/${PKGNAMEPREFIX}${PORTNAME}-bootstrap
.endif
RUN_DEPENDS+=	${PKGNAMEPREFIX}as:${PORTSDIR}/devel/${PKGNAMEPREFIX}binutils

CPE_VENDOR=	gnu
SSP_UNSAFE=	yes

WRKSRC=		${WRKDIR}/build-gcc
PATCH_WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=../${PORTNAME}-${PORTVERSION}/configure
CONFIGURE_ARGS+=--target=${GCC_TARGET} \
		--enable-languages=c,c++ \
		--disable-bootstrap \
		--disable-multilib \
		--disable-nls \
		--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} \
		--with-mpc=${LOCALBASE} \
		--with-system-zlib \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection for ${GCC_TARGET}" \
		--with-as=${LOCALBASE}/bin/${PKGNAMEPREFIX}as \
		--with-ld=${LOCALBASE}/bin/${PKGNAMEPREFIX}ld \
		--program-prefix=${PKGNAMEPREFIX}
.ifdef PKGNAMESUFFIX
CONFIGURE_ARGS+=--program-suffix=${PKGNAMESUFFIX} \
		--without-headers
.endif
.ifdef PKGNAMESUFFIX
PLIST=		${.CURDIR}/../${PKGNAMEPREFIX}${PORTNAME}/pkg-plist.${PKGNAMESUFFIX}
.endif
PLIST_SUB=	GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

GCC_TARGET=	${PKGNAMEPREFIX:C/-$//g}

.ifdef PKGNAMESUFFIX
ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

.if ${COMPILER_TYPE} == clang
MAKE_ARGS+=	CXXFLAGS=-fbracket-depth=512
.endif

post-extract:
	@${MKDIR} ${WRKSRC}

.include <bsd.port.post.mk>
