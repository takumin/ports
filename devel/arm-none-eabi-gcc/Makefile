# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	6.1.0
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	GCC:gcc
PKGNAMEPREFIX=	arm-none-eabi-
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.bz2:gcc

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	Cross GNU Compiler Collection for ${GCC_TARGET}

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

USES=		compiler cpe gmake iconv libtool makeinfo tar:bzip2
USE_PERL5=	build

LIB_DEPENDS+=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libmpc.so:math/mpc \
		libisl.so:devel/isl
BUILD_DEPENDS+=	${PKGNAMEPREFIX}as:devel/${PKGNAMEPREFIX}binutils
RUN_DEPENDS+=	${PKGNAMEPREFIX}as:devel/${PKGNAMEPREFIX}binutils

.ifndef PKGNAMESUFFIX
BUILD_DEPENDS+=	${PKGNAMEPREFIX}newlib:devel/${PKGNAMEPREFIX}newlib
.endif

CPE_VENDOR=	gnu
SSP_UNSAFE=	yes

GCC_TARGET=	${PKGNAMEPREFIX:C/-$//g}
LANGUAGES=	c,c++

GNU_CONFIGURE=	yes
CONFIGURE_OUTSOURCE=	yes
CONFIGURE_SCRIPT=../${PORTNAME}-${PORTVERSION}/configure
CONFIGURE_ARGS+=--target=${GCC_TARGET} \
		--program-prefix=${PKGNAMEPREFIX} \
		--enable-languages=${LANGUAGES} \
		--enable-interwork \
		--enable-multilib \
		--enable-lto \
		--enable-gnu-indirect-function \
		--disable-decimal-float \
		--disable-libffi \
		--disable-libgomp \
		--disable-libmudflap \
		--disable-libquadmath \
		--disable-libssp \
		--disable-libstdcxx-pch \
		--disable-nls \
		--disable-shared \
		--disable-threads \
		--disable-tls \
		--with-system-zlib \
		--with-newlib \
		--with-as=${LOCALBASE}/bin/${PKGNAMEPREFIX}as \
		--with-ld=${LOCALBASE}/bin/${PKGNAMEPREFIX}ld \
		--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} \
		--with-mpc=${LOCALBASE} \
		--with-isl=${LOCALBASE} \
		--with-pkgversion="FreeBSD Ports Collection for ${GCC_TARGET}" \
		--with-multilib-list=armv6-m,armv7-m,armv7e-m,armv7-r,aprofile \
		${ICONV_CONFIGURE_ARG}
.ifdef PKGNAMESUFFIX
CONFIGURE_ARGS+=--libdir=${PREFIX}/lib/${PKGNAMEPREFIX:C/-$//}${PKGNAMESUFFIX} \
		--libexecdir=${PREFIX}/libexec/${PKGNAMEPREFIX:C/-$//}${PKGNAMESUFFIX} \
		--program-suffix=${PKGNAMESUFFIX} \
		--without-headers
.endif
INFO_PATH=	info/${PKGNAMESUFFIX}gcc
PLIST_SUB=	GCC_TARGET=${GCC_TARGET} \
		GCC_VERSION=${PORTVERSION}

.ifdef PKGNAMESUFFIX
ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

.if ${COMPILER_TYPE} == "clang"
MAKE_ARGS+=	CXXFLAGS=-fbracket-depth=512
.endif

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for Host:${CONFIGURE_TARGET} Target:${GCC_TARGET} [${LANGUAGES}]"

.ifdef PKGNAMESUFFIX
post-stage:
	@${RM} -f ${STAGEDIR}${PREFIX}/bin/${PKGNAMEPREFIX}gcc-${PORTVERSION}
	@${RM} -f ${STAGEDIR}${PREFIX}/man/man1/*
	@${RM} -f ${STAGEDIR}${PREFIX}/man/man7/*
	@${RM} -fr ${STAGEDIR}${PREFIX}/info/${PKGNAMESUFFIX}gcc
.endif

.include <bsd.port.post.mk>
