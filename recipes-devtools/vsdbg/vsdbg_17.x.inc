###################################################################################################
# Contains additional parameters for the recipe to download the Visual Studio Remote debugger for
# all 17.x versions.
# Copyright Richard Dunkley, Sequent Logic LLC 2022
###################################################################################################
DESCRIPTION = "This does not build this version, it only pulls the binaries from Microsoft"
BUGTRACKER = "https://visualstudio.microsoft.com/"
SECTION = "runtime"
LICENSE = "CLOSED"

FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI += " \
	file://vsdbg.sh \
	"

S = "${WORKDIR}/vsdbg-${PV}"

require recipes-devtools/vsdbg/vsdbg_license.inc

DEPENDS = "zlib"
RDEPENDS_${PN} = "openssh openssh-sftp-server icu zlib"

INSANE_SKIP_${PN} += "already-stripped libdir textrel"

do_configure[noexec] = "1"
do_compile[noexec] = "1"

PACKAGES = "${PN}-dbg ${PN}"

FILES_${PN} += "${ROOT_HOME}"

do_install_prepend () {
	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/
	install -d ${D}${ROOT_HOME}/.vs-debugger/

	# Copy over the executable and then make a script to run it with certain
	# environemental variables set.
	install -m 0755 ${S}/vsdbg ${D}${ROOT_HOME}/.vs-debugger/vs2022/vsdbg2
	install -m 0755 ${WORKDIR}/vsdbg.sh ${D}${ROOT_HOME}/.vs-debugger/vs2022/vsdbg
	echo '${ROOT_HOME}/.vs-debugger/vs2022/vsdbg2' >> ${D}${ROOT_HOME}/.vs-debugger/vs2022/vsdbg

	install -m 0644 ${S}/license.txt ${D}${ROOT_HOME}/.vs-debugger/vs2022/
	install -m 0644 ${S}/ThirdPartyNotices.txt ${D}${ROOT_HOME}/.vs-debugger/vs2022/
	install -m 0644 ${S}/version.txt ${D}${ROOT_HOME}/.vs-debugger/vs2022/
	install -m 0644 ${S}/default.vsdbg-config.json ${D}${ROOT_HOME}/.vs-debugger/vs2022/
	install -m 0755 ${WORKDIR}/GetVsDbg.sh ${D}${ROOT_HOME}/.vs-debugger/

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1028/
	for file in ${S}/1028/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1028/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1029/
	for file in ${S}/1029/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1029/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1031/
	for file in ${S}/1031/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1031/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1033/
	for file in ${S}/1033/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1033/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1036/
	for file in ${S}/1036/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1036/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1040/
	for file in ${S}/1040/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1040/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1041/
	for file in ${S}/1041/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1041/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1042/
	for file in ${S}/1042/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1042/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1045/
	for file in ${S}/1045/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1045/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1046/
	for file in ${S}/1046/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1046/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1049/
	for file in ${S}/1049/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1049/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/1055/
	for file in ${S}/1055/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/1055/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/2052/
	for file in ${S}/2052/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/2052/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/3082/
	for file in ${S}/3082/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/3082/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/cs/
	for file in ${S}/cs/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/cs/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/de/
	for file in ${S}/de/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/de/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/es/
	for file in ${S}/es/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/es/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/fr/
	for file in ${S}/fr/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/fr/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/it/
	for file in ${S}/it/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/it/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/ja/
	for file in ${S}/ja/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/ja/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/ko/
	for file in ${S}/ko/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/ko/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/pl/
	for file in ${S}/pl/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/pl/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/pt-BR/
	for file in ${S}/pt-BR/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/pt-BR/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/ru/
	for file in ${S}/ru/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/ru/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/tr/
	for file in ${S}/tr/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/tr/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/zh-Hans/
	for file in ${S}/zh-Hans/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/zh-Hans/
	done

	install -d ${D}${ROOT_HOME}/.vs-debugger/vs2022/zh-Hant/
	for file in ${S}/zh-Hant/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/zh-Hant/
	done

	for file in ${S}/*.so; do
		install -m 0755 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/
	done
	for file in ${S}/*.dll; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/
	done
	for file in ${S}/*.vsdconfig; do
		install -m 0644 "$file" ${D}${ROOT_HOME}/.vs-debugger/vs2022/
	done

	# Setup a link so that vs2019 will also work.
	cd ${D}${ROOT_HOME}/.vs-debugger/
	ln -sf ${ROOT_HOME}/.vs-debugger/vs2022 vs2019
}

