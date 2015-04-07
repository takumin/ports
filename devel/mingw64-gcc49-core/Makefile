# Created by: Takumi Takahashi <takumiiinn@gmail.com>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.9.3.s20150325
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	snapshots/${DISTVERSION}
PKGNAMEPREFIX=	mingw-w64-
PKGNAMESUFFIX=	${SUFFIX}-core

MAINTAINER=	takumiiinn@gmail.com
COMMENT=	GNU Compiler Collection 4.9 for MinGW-w64

LICENSE=	GPLv3 GPLv3RLE
LICENSE_COMB=	multi

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libmpfr.so:${PORTSDIR}/math/mpfr \
		libmpc.so:${PORTSDIR}/math/mpc
BUILD_DEPENDS+=	${LOCALBASE}/bin/x86_64-w64-mingw32-as:${PORTSDIR}/devel/mingw-w64-binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/x86_64-w64-mingw32-as:${PORTSDIR}/devel/mingw-w64-binutils

CPE_VENDOR=	gnu
CPE_VERSION=	${GCC_VERSION}
UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

# DISTVERSION relates to downloads, GCC_VERSION and SUFFIX to names
# of executables and directories once installed.  A PORTVERSION of
# 4.Y.2.s20130808 results in values of 4.Y-20130808, 4.Y.2, and 4Y
# for these three.
DISTVERSION=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.s([0-9]+)/\1-\2/}
GCC_VERSION=	${PORTVERSION:C/(.+)\.s[0-9]{8}/\1/}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
ONLY_FOR_ARCHS=	amd64 i386
USES=		cpe gmake iconv libtool makeinfo perl5 tar:bzip2
USE_BINUTILS=	yes
USE_PERL5=	build
SSP_UNSAFE=	yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:S/${WRKDIR}\///}/configure

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-${OPSYS:tl}${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-${OPSYS:tl}${OSREL}
.endif

LANGUAGES:=	c,c++
SRCDIR=		${WRKDIR}/gcc-${DISTVERSION}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-bootstrap \
		--disable-nls \
		--enable-languages=${LANGUAGES} \
		--target=x86_64-w64-mingw32 \
		--program-prefix=x86_64-w64-mingw32- \
		--enable-gnu-indirect-function \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--program-suffix=${SUFFIX} \
		--with-as=${LOCALBASE}/bin/as \
		--with-gmp=${LOCALBASE} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--with-ld=${LOCALBASE}/bin/ld \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB=	GCC_VERSION=${GCC_VERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccinstall \
		gcc${SUFFIX}/gccint

SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${CONFIGURE_TARGET} [${LANGUAGES}]"

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-stage:
	${RM} -f ${STAGEDIR}${PREFIX}/man/man7/*
	${RM} -f ${STAGEDIR}${PREFIX}/bin/rebuild-gcj-db${SUFFIX} \
	         ${STAGEDIR}${PREFIX}/man/man1/rebuild-gcj-db${SUFFIX}.1
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///} include/gcj include/gnu include/java include/javax
	cd ${STAGEDIR}${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
