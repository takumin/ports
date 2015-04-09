# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.9.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${DISTVERSION}

MAINTAINER?=	takumiiinn@gmail.com
COMMENT?=	GNU Compiler Collection 4.9 for MinGW-w64

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc

CPE_VENDOR=	gnu

ONLY_FOR_ARCHS=	amd64 i386
USES=		cpe gmake iconv libtool makeinfo perl5 tar:bzip2
USE_PERL5=	build
SSP_UNSAFE=	yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:S/${WRKDIR}\///}/configure

.include <bsd.port.pre.mk>

.ifndef PKGNAMEPREFIX
IGNORE=		build for 'devel/mingw-w64-i686-gcc' or 'devel/mingw-w64-x86_64-gcc'
.endif

CROSS_ARCH=	${PKGNAMEPREFIX:C/^mingw-w64-(.*)-$/\1/}
CROSS_TARGET=	${CROSS_ARCH}-w64-mingw32

.ifdef PKGNAMESUFFIX
ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc
BUILD_DEPENDS+=	${LOCALBASE}/${CROSS_TARGET}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-headers \
		${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-binutils
RUN_DEPENDS+=	${LOCALBASE}/${CROSS_TARGET}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-headers \
		${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-binutils
.else
LIB_DEPENDS+=	${LOCALBASE}/${CROSS_TARGET}/lib/libmingw32.a:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-crt
.endif

.if ! ( ${CROSS_TARGET} == "i686-w64-mingw32" || ${CROSS_TARGET} == "x86_64-w64-mingw32" )
IGNORE=		support target for "i686-w64-mingw32" or "x86_64-w64-mingw32"
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

LANGUAGES:=	c,c++
SRCDIR=		${WRKDIR}/gcc-${DISTVERSION}
WRKSRC=		${WRKDIR}/build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--target=${CROSS_TARGET} \
		--enable-languages=${LANGUAGES} \
		--enable-shared \
		--enable-static \
		--enable-fully-dynamic-string \
		--enable-libstdcxx-time=yes \
		--disable-multilib \
		--disable-bootstrap \
		--disable-nls \
		--disable-win32-registry \
		--disable-libssp \
		--program-prefix=${CROSS_TARGET}- \
		--with-as=${LOCALBASE}/bin/${CROSS_TARGET}-as \
		--with-ld=${LOCALBASE}/bin/${CROSS_TARGET}-ld \
		--with-gmp=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection for MinGW-w64" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${PREFIX}/lib/gcc/${CROSS_TARGET}/${PORTVERSION}
PLIST_SUB=	GCC_VERSION=${PORTVERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		GNU_TARGET=${CROSS_TARGET}
INFO=		${CROSS_TARGET}-gcc/cpp \
		${CROSS_TARGET}-gcc/cppinternals \
		${CROSS_TARGET}-gcc/gcc \
		${CROSS_TARGET}-gcc/gccinstall \
		${CROSS_TARGET}-gcc/gccint
SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for Host:${CONFIGURE_TARGET} Target:${CROSS_TARGET} [${LANGUAGES}]"

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-stage:
	${RM} -f ${STAGEDIR}${PREFIX}/man/man7/*

.include <bsd.port.post.mk>
