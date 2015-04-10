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

CPE_VENDOR=	gnu

ONLY_FOR_ARCHS=	amd64 i386

.ifndef PKGNAMEPREFIX
IGNORE=		build for 'devel/mingw-w64-i686-gcc' or 'devel/mingw-w64-x86_64-gcc'
.else
CROSS_ARCH=	${PKGNAMEPREFIX:C/^mingw-w64-(.*)-$/\1/}
CROSS_TARGET=	${CROSS_ARCH}-w64-mingw32
. if ! ( ${CROSS_ARCH} == "i686" || ${CROSS_ARCH} == "x86_64" )
IGNORE=		support target for "i686-w64-mingw32" or "x86_64-w64-mingw32"
. endif
.endif

USES=		cpe gmake iconv libtool makeinfo perl5 tar:bzip2
USE_PERL5=	build
SSP_UNSAFE=	yes
LIB_DEPENDS+=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-binutils \
		${LOCALBASE}/${CROSS_TARGET}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-headers
RUN_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-binutils \
		${LOCALBASE}/${CROSS_TARGET}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-headers
.ifndef PKGNAMESUFFIX
BUILD_DEPENDS+=	${LOCALBASE}/${CROSS_TARGET}/lib/libmingw32.a:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-crt
RUN_DEPENDS+=	${LOCALBASE}/${CROSS_TARGET}/lib/libmingw32.a:${PORTSDIR}/devel/mingw-w64-${CROSS_ARCH}-crt
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

.ifdef PKGNAMESUFFIX
ALL_TARGET=	all-gcc all-target-libgcc
INSTALL_TARGET=	install-gcc install-target-libgcc
UNIQUENAME=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
.endif

SRCDIR=			${WRKDIR}/gcc-${DISTVERSION}
WRKSRC=			${WRKDIR}/build
PATCH_WRKSRC=		${SRCDIR}
LANGUAGES:=		c,c++
BINARIES=		c++ cpp g++ gcc gcov
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	../${SRCDIR:S/${WRKDIR}\///}/configure
.ifdef PKGNAMESUFFIX
CONFIGURE_ARGS+=	--program-prefix=${CROSS_TARGET}- \
			--program-suffix=${PKGNAMESUFFIX}
.endif
CONFIGURE_ARGS+=	--libdir=${PREFIX}/lib/mingw-w64${PKGNAMESUFFIX} \
			--libexecdir=${PREFIX}/libexec/mingw-w64${PKGNAMESUFFIX} \
			--target=${CROSS_TARGET} \
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
			--without-headers \
			--with-as=${LOCALBASE}/bin/${CROSS_TARGET}-as \
			--with-ld=${LOCALBASE}/bin/${CROSS_TARGET}-ld \
			--with-gmp=${LOCALBASE} \
			${ICONV_CONFIGURE_ARG} \
			--with-pkgversion="FreeBSD Ports Collection for MinGW-w64" \
			--with-system-zlib
MAKE_ARGS+=		MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=		${PREFIX}/lib/mingw-w64${PKGNAMESUFFIX}
PLIST_SUB=		GCC_VERSION=${PORTVERSION} \
			GNU_HOST=${CONFIGURE_TARGET} \
			GNU_TARGET=${CROSS_TARGET}
PLIST=			${.CURDIR}/../mingw-gcc/pkg-plist${PKGNAMESUFFIX:C/^-/\./}
.ifndef PKGNAMESUFFIX
INFO_PATH=		info/${CROSS_TARGET}-gcc
INFO=			cpp cppinternals gcc gccinstall gccint
.endif
SUB_FILES=		pkg-message

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for Host:${CONFIGURE_TARGET} Target:${CROSS_TARGET} [${LANGUAGES}]"

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-stage:
.ifdef PKGNAMESUFFIX
	${RM} -rf ${STAGEDIR}${PREFIX}/include
	${RM} -rf ${STAGEDIR}${PREFIX}/info
	${RM} -f ${STAGEDIR}${PREFIX}/man/man1/*
.endif
	${RM} -f ${STAGEDIR}${PREFIX}/man/man7/*
	${MKDIR} ${STAGEDIR}${PREFIX}/${CROSS_TARGET}/bin
.for F in ${BINARIES}
. ifdef PKGNAMESUFFIX
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${CROSS_TARGET}-$F${PKGNAMESUFFIX} \
		${STAGEDIR}${PREFIX}/${CROSS_TARGET}/bin/$F${PKGNAMESUFFIX}
. else
	${LN} -f ${STAGEDIR}${PREFIX}/bin/${CROSS_TARGET}-$F \
		${STAGEDIR}${PREFIX}/${CROSS_TARGET}/bin/$F
. endif
.endfor

.include <bsd.port.post.mk>
