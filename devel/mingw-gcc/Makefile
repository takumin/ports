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
USE_PERL5=	build
SSP_UNSAFE=	yes

.include <bsd.port.pre.mk>

.ifndef CROSS_TARGET
IGNORE=		build for 'devel/mingw32-gcc' or 'devel/mingw64-gcc'
.endif

LANGUAGES:=	c,c++
SRCDIR=		${WRKDIR}/gcc-${DISTVERSION}
WRKSRC=		${WRKDIR}/build
PATCH_WRKSRC=	${SRCDIR}
TARGLIB=	${PREFIX}/lib/${CROSS_TARGET}-gcc
LIBEXEC=	${PREFIX}/libexec/${CROSS_TARGET}-gcc
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../${SRCDIR:S/${WRKDIR}\///}/configure
CONFIGURE_ARGS+=--target=${CROSS_TARGET} \
		--enable-targets=all \
		--enable-languages=${LANGUAGES} \
		--disable-win32-registory \
		--disable-nls \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--with-gxx-include-dir=${TARGLIB}/include/c++ \
		--with-as=${LOCALBASE}/bin/${CROSS_TARGET}-as \
		--with-ld=${LOCALBASE}/bin/${CROSS_TARGET}-ld \
		--with-gmp=${LOCALBASE} \
		--with-mpfr=${LOCALBASE} \
		--with-mpc=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB=	GCC_VERSION=${PORTVERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		CROSS_TARGET=${CROSS_TARGET}
PLIST_DIRS=	${PREFIX}/info/${CROSS_TARGET}-gcc
INFO_PATH=	info/${CROSS_TARGET}-gcc
INFO=		cpp cppinternals gcc gccinstall gccint
SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION}"
	@${ECHO_MSG} "Host:      [${CONFIGURE_TARGET}]"
	@${ECHO_MSG} "Target:    [${CROSS_TARGET}]"
	@${ECHO_MSG} "Languages: [${LANGUAGES}]"

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-stage:
	${RM} -f ${STAGEDIR}${PREFIX}/man/man7/*
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///}
	cd ${STAGEDIR}${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
