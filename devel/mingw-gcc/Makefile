# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.9.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/${PORTNAME}-${PORTVERSION}

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	GNU Compiler Collection 4.9 for MinGW-w64

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc

CPE_VENDOR=	gnu

ONLY_FOR_ARCHS=	amd64 i386
USES=		cpe gmake iconv libtool makeinfo perl5 tar:bzip2
USE_BINUTILS=	yes
USE_PERL5=	build
SSP_UNSAFE=	yes

.include <bsd.port.pre.mk>

.ifdef CROSS_CORE
ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc
.endif

.ifndef CROSS_TARGET
IGNORE=		Require CROSS_TARGET for "x86_64-pc-mingw32" or "i686-pc-mingw32"
.else
. if ${CROSS_TARGET} == "x86_64-w64-mingw32"
PKGNAMEPREFIX=	mingw64-
BUILD_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw64-binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw64-binutils
. elif ${CROSS_TARGET} == "i686-pc-mingw32"
PKGNAMEPREFIX=	mingw32-
BUILD_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw32-binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/${CROSS_TARGET}-as:${PORTSDIR}/devel/mingw32-binutils
. else
IGNORE=		Require CROSS_TARGET for "x86_64-pc-mingw32" or "i686-pc-mingw32"
. endif
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	i386-portbld-${OPSYS:tl}${OSREL}
.endif

LANGUAGES:=	c,c++
SRCDIR=		${WRKDIR}/gcc-${DISTVERSION}
WRKSRC=		${WRKDIR}/build
PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:S/${WRKDIR}\///}/configure
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--target=${CROSS_TARGET} \
		--enable-languages=${LANGUAGES} \
		--disable-bootstrap \
		--disable-nls \
		--with-as=${LOCALBASE}/bin/${CROSS_TARGET}-as \
		--with-ld=${LOCALBASE}/bin/${CROSS_TARGET}-ld \
		--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} \
		--with-mpc=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	yes
PLIST_SUB=	GCC_VERSION=${PORTVERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		CROSS_TARGET=${CROSS_TARGET}
INFO=		gcc/cpp \
		gcc/cppinternals \
		gcc/gcc \
		gcc/gccinstall \
		gcc/gccint
SUB_FILES=	pkg-message

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION}"
	@${ECHO_MSG} "Host:      [${CONFIGURE_TARGET}]"
	@${ECHO_MSG} "Target:    [${CROSS_TARGET}]"
	@${ECHO_MSG} "Languages: [${LANGUAGES}]"

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

.include <bsd.port.post.mk>
