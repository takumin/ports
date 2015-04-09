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

# DISTVERSION relates to downloads, GCC_VERSION and SUFFIX to names
# of executables and directories once installed.
DISTVERSION=	${PORTVERSION}
GCC_VERSION=	${PORTVERSION:C/(.+)\.[0-9]{8}/\1/}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
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

TARGET_ARCH=	${PKGNAMEPREFIX:C/^mingw-w64-(.*)-$/\1/}-w64-mingw32

.ifdef PKGNAMESUFFIX
ALL_TARGET=	all-gcc
INSTALL_TARGET=	install-gcc
.else
. if ${TARGET_ARCH} == "i686-w64-mingw32"
LIB_DEPENDS+=	${LOCALBASE}/${TARGET_ARCH}/lib/libmingw32.a:${PORTSDIR}/devel/mingw-w64-i686-crt
. else
LIB_DEPENDS+=	${LOCALBASE}/${TARGET_ARCH}/lib/libmingw32.a:${PORTSDIR}/devel/mingw-w64-x86_64-crt
. endif
.endif

.if ${TARGET_ARCH} == "i686-w64-mingw32"
BUILD_DEPENDS+=	${LOCALBASE}/bin/${TARGET_ARCH}-as:${PORTSDIR}/devel/mingw-w64-i686-binutils \
		${LOCALBASE}/${TARGET_ARCH}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-i686-headers
RUN_DEPENDS+=	${LOCALBASE}/bin/${TARGET_ARCH}-as:${PORTSDIR}/devel/mingw-w64-i686-binutils \
		${LOCALBASE}/${TARGET_ARCH}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-i686-headers
.elif ${TARGET_ARCH} == "x86_64-w64-mingw32"
BUILD_DEPENDS+=	${LOCALBASE}/bin/${TARGET_ARCH}-as:${PORTSDIR}/devel/mingw-w64-x86_64-binutils \
		${LOCALBASE}/${TARGET_ARCH}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-x86_64-headers
RUN_DEPENDS+=	${LOCALBASE}/bin/${TARGET_ARCH}-as:${PORTSDIR}/devel/mingw-w64-x86_64-binutils \
		${LOCALBASE}/${TARGET_ARCH}/include/_mingw.h:${PORTSDIR}/devel/mingw-w64-x86_64-headers
.else
IGNORE=		support target arch for "i686-w64-mingw32" or "x86_64-w64-mingw32"
.endif

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
CONFIGURE_ARGS+=--target=${TARGET_ARCH} \
		--enable-languages=${LANGUAGES} \
		--enable-shared \
		--enable-static \
		--disable-multilib \
		--disable-bootstrap \
		--disable-nls \
		--disable-libssp \
		--disable-win32-registry \
		--program-prefix=${TARGET_ARCH}- \
		--program-suffix=${SUFFIX} \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--with-gxx-include-dir=${TARGLIB}/include/c++ \
		--with-as=${LOCALBASE}/bin/${TARGET_ARCH}-as \
		--with-ld=${LOCALBASE}/bin/${TARGET_ARCH}-ld \
		--with-gmp=${LOCALBASE} \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection for MinGW-w64" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB=	GCC_VERSION=${GCC_VERSION} \
		GNU_HOST=${CONFIGURE_TARGET} \
		GNU_TARGET=${TARGET_ARCH} \
		SUFFIX=${SUFFIX}
INFO=		${TARGET_ARCH}-gcc${SUFFIX}/cpp \
		${TARGET_ARCH}-gcc${SUFFIX}/cppinternals \
		${TARGET_ARCH}-gcc${SUFFIX}/gcc \
		${TARGET_ARCH}-gcc${SUFFIX}/gccinstall \
		${TARGET_ARCH}-gcc${SUFFIX}/gccint
SUB_FILES=	pkg-message
SUB_LIST+=	TARGLIB=${TARGLIB}

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${CONFIGURE_TARGET} [${LANGUAGES}]"

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
