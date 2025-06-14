// SoftEther VPN Source Code - Stable Edition Repository
// Mayaqua Kernel
// 
// SoftEther VPN Server, Client and Bridge are free software under the Apache License, Version 2.0.
// 
// Copyright (c) Daiyuu Nobori.
// Copyright (c) SoftEther VPN Project, University of Tsukuba, Japan.
// Copyright (c) SoftEther Corporation.
// Copyright (c) all contributors on SoftEther VPN project in GitHub.
// 
// All Rights Reserved.
// 
// http://www.softether.org/
// 
// This stable branch is officially managed by Daiyuu Nobori, the owner of SoftEther VPN Project.
// Pull requests should be sent to the Developer Edition Master Repository on https://github.com/SoftEtherVPN/SoftEtherVPN
// 
// License: The Apache License, Version 2.0
// https://www.apache.org/licenses/LICENSE-2.0
// 
// DISCLAIMER
// ==========
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
// 
// THIS SOFTWARE IS DEVELOPED IN JAPAN, AND DISTRIBUTED FROM JAPAN, UNDER
// JAPANESE LAWS. YOU MUST AGREE IN ADVANCE TO USE, COPY, MODIFY, MERGE, PUBLISH,
// DISTRIBUTE, SUBLICENSE, AND/OR SELL COPIES OF THIS SOFTWARE, THAT ANY
// JURIDICAL DISPUTES WHICH ARE CONCERNED TO THIS SOFTWARE OR ITS CONTENTS,
// AGAINST US (SOFTETHER PROJECT, SOFTETHER CORPORATION, DAIYUU NOBORI OR OTHER
// SUPPLIERS), OR ANY JURIDICAL DISPUTES AGAINST US WHICH ARE CAUSED BY ANY KIND
// OF USING, COPYING, MODIFYING, MERGING, PUBLISHING, DISTRIBUTING, SUBLICENSING,
// AND/OR SELLING COPIES OF THIS SOFTWARE SHALL BE REGARDED AS BE CONSTRUED AND
// CONTROLLED BY JAPANESE LAWS, AND YOU MUST FURTHER CONSENT TO EXCLUSIVE
// JURISDICTION AND VENUE IN THE COURTS SITTING IN TOKYO, JAPAN. YOU MUST WAIVE
// ALL DEFENSES OF LACK OF PERSONAL JURISDICTION AND FORUM NON CONVENIENS.
// PROCESS MAY BE SERVED ON EITHER PARTY IN THE MANNER AUTHORIZED BY APPLICABLE
// LAW OR COURT RULE.
// 
// USE ONLY IN JAPAN. DO NOT USE THIS SOFTWARE IN ANOTHER COUNTRY UNLESS YOU HAVE
// A CONFIRMATION THAT THIS SOFTWARE DOES NOT VIOLATE ANY CRIMINAL LAWS OR CIVIL
// RIGHTS IN THAT PARTICULAR COUNTRY. USING THIS SOFTWARE IN OTHER COUNTRIES IS
// COMPLETELY AT YOUR OWN RISK. THE SOFTETHER VPN PROJECT HAS DEVELOPED AND
// DISTRIBUTED THIS SOFTWARE TO COMPLY ONLY WITH THE JAPANESE LAWS AND EXISTING
// CIVIL RIGHTS INCLUDING PATENTS WHICH ARE SUBJECTS APPLY IN JAPAN. OTHER
// COUNTRIES' LAWS OR CIVIL RIGHTS ARE NONE OF OUR CONCERNS NOR RESPONSIBILITIES.
// WE HAVE NEVER INVESTIGATED ANY CRIMINAL REGULATIONS, CIVIL LAWS OR
// INTELLECTUAL PROPERTY RIGHTS INCLUDING PATENTS IN ANY OF OTHER 200+ COUNTRIES
// AND TERRITORIES. BY NATURE, THERE ARE 200+ REGIONS IN THE WORLD, WITH
// DIFFERENT LAWS. IT IS IMPOSSIBLE TO VERIFY EVERY COUNTRIES' LAWS, REGULATIONS
// AND CIVIL RIGHTS TO MAKE THE SOFTWARE COMPLY WITH ALL COUNTRIES' LAWS BY THE
// PROJECT. EVEN IF YOU WILL BE SUED BY A PRIVATE ENTITY OR BE DAMAGED BY A
// PUBLIC SERVANT IN YOUR COUNTRY, THE DEVELOPERS OF THIS SOFTWARE WILL NEVER BE
// LIABLE TO RECOVER OR COMPENSATE SUCH DAMAGES, CRIMINAL OR CIVIL
// RESPONSIBILITIES. NOTE THAT THIS LINE IS NOT LICENSE RESTRICTION BUT JUST A
// STATEMENT FOR WARNING AND DISCLAIMER.
// 
// READ AND UNDERSTAND THE 'WARNING.TXT' FILE BEFORE USING THIS SOFTWARE.
// SOME SOFTWARE PROGRAMS FROM THIRD PARTIES ARE INCLUDED ON THIS SOFTWARE WITH
// LICENSE CONDITIONS WHICH ARE DESCRIBED ON THE 'THIRD_PARTY.TXT' FILE.
// 
// 
// SOURCE CODE CONTRIBUTION
// ------------------------
// 
// Your contribution to SoftEther VPN Project is much appreciated.
// Please send patches to us through GitHub.
// Read the SoftEther VPN Patch Acceptance Policy in advance:
// http://www.softether.org/5-download/src/9.patch
// 
// 
// DEAR SECURITY EXPERTS
// ---------------------
// 
// If you find a bug or a security vulnerability please kindly inform us
// about the problem immediately so that we can fix the security problem
// to protect a lot of users around the world as soon as possible.
// 
// Our e-mail address for security reports is:
// softether-vpn-security [at] softether.org
// 
// Please note that the above e-mail address is not a technical support
// inquiry address. If you need technical assistance, please visit
// http://www.softether.org/ and ask your question on the users forum.
// 
// Thank you for your cooperation.
// 
// 
// NO MEMORY OR RESOURCE LEAKS
// ---------------------------
// 
// The memory-leaks and resource-leaks verification under the stress
// test has been passed before release this source code.


// FileIO.h
// Header of FileIO.c

#ifndef	FILEIO_H
#define	FILEIO_H

// Constant
#define	HAMCORE_DIR_NAME			"hamcore"
#define	HAMCORE_FILE_NAME			"hamcore.se2"
#define	HAMCORE_FILE_NAME_2			"_hamcore.se2"
#define	HAMCORE_TEXT_NAME			"hamcore.txt"
#define	HAMCORE_HEADER_DATA			"HamCore"
#define	HAMCORE_HEADER_SIZE			7
#define	HAMCORE_CACHE_EXPIRES		(5 * 60 * 1000)

// IO structure
struct IO
{
	char Name[MAX_SIZE];
	wchar_t NameW[MAX_SIZE];
	void *pData;
	bool WriteMode;
	bool HamMode;
	BUF *HamBuf;
	UINT64 SetUpdateTime, SetCreateTime;
	UINT64 GetUpdateTime, GetCreateTime, GetAccessTime;
};

// HC structure
typedef struct HC
{
	char *FileName;				// File name
	UINT Size;					// File size
	UINT SizeCompressed;		// Compressed file size
	UINT Offset;				// Offset
	void *Buffer;				// Buffer
	UINT64 LastAccess;			// Access Date
} HC;

// DIRENT structure
struct DIRENT
{
	bool Folder;				// Folder
	char *FileName;				// File name (ANSI)
	wchar_t *FileNameW;			// File name (Unicode)
	UINT64 FileSize;			// File size
	UINT64 CreateDate;			// Creation Date
	UINT64 UpdateDate;			// Updating date
};

// DIRLIST structure
struct DIRLIST
{
	UINT NumFiles;				// Number of files
	struct DIRENT **File;			// File array
};

// ZIP related structure
#ifdef	OS_WIN32
#pragma pack(push, 1)
#endif	// OS_WIN32

struct ZIP_DATA_HEADER
{
	UINT Signature;
	USHORT NeedVer;
	USHORT Option;
	USHORT CompType;
	USHORT FileTime;
	USHORT FileDate;
	UINT Crc32;
	UINT CompSize;
	UINT UncompSize;
	USHORT FileNameLen;
	USHORT ExtraLen;
} GCC_PACKED;

struct ZIP_DATA_FOOTER
{
	UINT Signature;
	UINT Crc32;
	UINT CompSize;
	UINT UncompSize;
} GCC_PACKED;

struct ZIP_DIR_HEADER
{
	UINT Signature;
	USHORT MadeVer;
	USHORT NeedVer;
	USHORT Option;
	USHORT CompType;
	USHORT FileTime;
	USHORT FileDate;
	UINT Crc32;
	UINT CompSize;
	UINT UncompSize;
	USHORT FileNameLen;
	USHORT ExtraLen;
	USHORT CommentLen;
	USHORT DiskNum;
	USHORT InAttr;
	UINT OutAttr;
	UINT HeaderPos;
} GCC_PACKED;

struct ZIP_END_HEADER
{
	UINT Signature;
	USHORT DiskNum;
	USHORT StartDiskNum;
	USHORT DiskDirEntry;
	USHORT DirEntry;
	UINT DirSize;
	UINT StartPos;
	USHORT CommentLen;
} GCC_PACKED;

#define	ZIP_SIGNATURE				0x04034B50
#define	ZIP_SIGNATURE_END			0x06054B50
#define	ZIP_VERSION					10
#define	ZIP_VERSION_WITH_COMPRESS	20

#ifdef	OS_WIN32
#pragma pack(pop)
#endif	// OS_WIN32

struct ZIP_FILE
{
	char Name[MAX_PATH];
	UINT Size;
	UINT64 DateTime;
	UINT Attributes;
	UINT CurrentSize;
	UINT CompressSize;
	UINT Crc32;
	UINT HeaderPos;
};

struct ZIP_PACKER
{
	FIFO *Fifo;
	LIST *FileList;
	ZIP_FILE *CurrentFile;
};

struct ENUM_DIR_WITH_SUB_DATA
{
	LIST *FileList;
};

void InitCrc32();
UINT Crc32(void *buf, UINT pos, UINT len);
UINT Crc32First(void *buf, UINT pos, UINT len);
UINT Crc32Next(void *buf, UINT pos, UINT len, UINT last_crc32);
UINT Crc32Finish(UINT last_crc32);
void WriteZipDataHeader(ZIP_FILE *f, ZIP_DATA_HEADER *h, bool write_sizes);
void WriteZipDataFooter(ZIP_FILE *f, ZIP_DATA_FOOTER *h);
ZIP_PACKER *NewZipPacker();
void FreeZipPacker(ZIP_PACKER *p);
void ZipAddFileSimple(ZIP_PACKER *p, char *name, UINT64 dt, UINT attribute, void *data, UINT size);
bool ZipAddRealFileW(ZIP_PACKER *p, char *name, UINT64 dt, UINT attribute, wchar_t *srcname);
bool ZipAddRealFile(ZIP_PACKER *p, char *name, UINT64 dt, UINT attribute, char *srcname);
void ZipAddFileStart(ZIP_PACKER *p, char *name, UINT size, UINT64 dt, UINT attribute);
UINT ZipAddFileData(ZIP_PACKER *p, void *data, UINT pos, UINT len);
void ZipAddFileFooter(ZIP_PACKER *p);
FIFO *ZipFinish(ZIP_PACKER *p);
bool ZipWriteW(ZIP_PACKER *p, wchar_t *name);

int DeleteDirInner(char *name);
int DeleteDirInnerW(wchar_t *name);
int DeleteDir(char *name);
int DeleteDirW(wchar_t *name);
int MakeDirInner(char *name);
int MakeDirInnerW(wchar_t *name);
int MakeDir(char *name);
int MakeDirW(wchar_t *name);
int MakeDirEx(char *name);
int MakeDirExW(wchar_t *name);
int FileDeleteInner(char *name);
int FileDeleteInnerW(wchar_t *name);
int FileDelete(char *name);
int FileDeleteW(wchar_t *name);
int FileSeek(IO *o, UINT mode, int offset);
UINT FileSize(IO *o);
UINT64 FileSize64(IO *o);
UINT FileSizeEx(char *name);
UINT FileSizeExW(wchar_t *name);
int FileRead(IO *o, void *buf, UINT size);
int FileWrite(IO *o, void *buf, UINT size);
void FileFlush(IO *o);
void FileClose(IO *o);
void FileCloseEx(IO *o, int no_flush);
void FileCloseAndDelete(IO *o);
IO *FileCreateInner(char *name);
IO *FileCreateInnerW(wchar_t *name);
IO *FileCreate(char *name);
IO *FileCreateW(wchar_t *name);
int FileWriteAll(char *name, void *data, UINT size);
int FileWriteAllW(wchar_t *name, void *data, UINT size);
IO *FileOpenInner(char *name, int write_mode, int read_lock);
IO *FileOpenInnerW(wchar_t *name, int write_mode, int read_lock);
IO *FileOpen(char *name, int write_mode);
IO *FileOpenW(wchar_t *name, int write_mode);
IO *FileOpenEx(char *name, int write_mode, int read_lock);
IO *FileOpenExW(wchar_t *name, int write_mode, int read_lock);
void ConvertPath(char *path);
void ConvertPathW(wchar_t *path);
int FileRenameInner(char *old_name, char *new_name);
int FileRenameInnerW(wchar_t *old_name, wchar_t *new_name);
int FileRename(char *old_name, char *new_name);
int FileRenameW(wchar_t *old_name, wchar_t *new_name);
void NormalizePath(char *dst, UINT size, char *src);
void NormalizePathW(wchar_t *dst, UINT size, wchar_t *src);
int GetRelativePathW(wchar_t *dst, UINT size, wchar_t *fullpath, wchar_t *basepath);
int GetRelativePath(char *dst, UINT size, char *fullpath, char *basepath);
TOKEN_LIST *ParseSplitedPath(char *path);
UNI_TOKEN_LIST *ParseSplitedPathW(wchar_t *path);
char *GetCurrentPathEnvStr();
int IsFileExistsInner(char *name);
int IsFileExistsInnerW(wchar_t *name);
int IsFileExists(char *name);
int IsFileExistsW(wchar_t *name);
void InnerFilePath(char *dst, UINT size, char *src);
void InnerFilePathW(wchar_t *dst, UINT size, wchar_t *src);
void ConbinePath(char *dst, UINT size, char *dirname, char *filename);
void ConbinePathW(wchar_t *dst, UINT size, wchar_t *dirname, wchar_t *filename);
void CombinePath(char *dst, UINT size, char *dirname, char *filename);
void CombinePathW(wchar_t *dst, UINT size, wchar_t *dirname, wchar_t *filename);
void GetDirNameFromFilePath(char *dst, UINT size, char *filepath);
void GetDirNameFromFilePathW(wchar_t *dst, UINT size, wchar_t *filepath);
void GetFileNameFromFilePath(char *dst, UINT size, char *filepath);
void GetFileNameFromFilePathW(wchar_t *dst, UINT size, wchar_t *filepath);
void MakeSafeFileName(char *dst, UINT size, char *src);
void MakeSafeFileNameW(wchar_t *dst, UINT size, wchar_t *src);
void InitGetExeName(char *arg);
void UnixGetExeNameW(wchar_t *name, UINT size, wchar_t *arg);
void GetExeName(char *name, UINT size);
void GetExeNameW(wchar_t *name, UINT size);
void GetExeDir(char *name, UINT size);
void GetExeDirW(wchar_t *name, UINT size);
void BuildHamcore(char *dst_filename, char *src_dir, bool unix_only);
int CompareHamcore(void *p1, void *p2);
void InitHamcore();
void FreeHamcore();
BUF *ReadHamcore(char *name);
BUF *ReadHamcoreW(wchar_t *filename);
void SafeFileName(char *name);
void SafeFileNameW(wchar_t *name);
void UniSafeFileName(wchar_t *name);
DIRLIST *EnumDir(char *dirname);
DIRLIST *EnumDirW(wchar_t *dirname);
DIRLIST *EnumDirEx(char *dirname, COMPARE *compare);
DIRLIST *EnumDirExW(wchar_t *dirname, COMPARE *compare);
UNI_TOKEN_LIST *EnumDirWithSubDirsW(wchar_t *dirname);
TOKEN_LIST *EnumDirWithSubDirs(char *dirname);
void EnumDirWithSubDirsMain(ENUM_DIR_WITH_SUB_DATA *d, wchar_t *dirname);
void FreeDir(DIRLIST *d);
int CompareDirListByName(void *p1, void *p2);
bool GetDiskFree(char *path, UINT64 *free_size, UINT64 *used_size, UINT64 *total_size);
bool GetDiskFreeW(wchar_t *path, UINT64 *free_size, UINT64 *used_size, UINT64 *total_size);
void ConvertSafeFileName(char *dst, UINT size, char *src);
void ConvertSafeFileNameW(wchar_t *dst, UINT size, wchar_t *src);
bool FileReplaceRename(char *old_name, char *new_name);
bool FileReplaceRenameW(wchar_t *old_name, wchar_t *new_name);
bool IsFile(char *name);
bool IsFileW(wchar_t *name);
void GetCurrentDirW(wchar_t *name, UINT size);
void GetCurrentDir(char *name, UINT size);
bool SaveFileW(wchar_t *name, void *data, UINT size);
bool SaveFile(char *name, void *data, UINT size);
bool IsFileWriteLockedW(wchar_t *name);
bool IsFileWriteLocked(char *name);
bool IsInLines(BUF *buf, char *str, bool instr);
bool IsInLinesFile(wchar_t *filename, char *str, bool instr);

#endif	// FILEIO_H



