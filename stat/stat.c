#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>
#include <stdio.h>
#include <fcntl.h>
#include <time.h>
#include <grp.h>
#include <pwd.h>

#define SMALL_BUFFER_SIZE 512
#define FILE_TYPE_STRING "Type du fichier :"

int printFormattedDate(struct timespec ts, char prefix[]) {
    struct tm result;
    localtime_r(&ts.tv_sec, &result);
    char str_date[SMALL_BUFFER_SIZE];
    strftime(str_date, sizeof(str_date), "%F %T", &result);
    printf("%s %s\n", prefix, str_date);

    return 0;
}

int main(int argc, char *argv[]) {
    // vérifie qu'on a bien un argument à utiliser
    assert(argc > 1);

    // chemin du dossier
    char folderpath[SMALL_BUFFER_SIZE];
    getcwd(folderpath, SMALL_BUFFER_SIZE);    

    // open sur dossier parent
    int dirfd, fstatatfd;
    dirfd = open(folderpath, O_RDONLY);
    assert(dirfd != -1);
    
    // création structure stat
    struct stat s;
    struct stat *spointeur;
    spointeur = &s;

    // appel à fstatat pour récupérer les informations à afficher
    fstatatfd = fstatat(dirfd, argv[1], spointeur, 0);
    assert(fstatatfd != -1);

    // ex13
    struct passwd *pwd;
    pwd = getpwuid(s.st_uid);
    struct group *grp;
    grp = getgrgid(pwd->pw_gid);
    printf("username : %s \n", pwd->pw_name);
    printf("user informations : %s \n", pwd->pw_gecos);
    printf("user group name : %s \n", grp->gr_name);

    // ligne 1
    printf("Fichier : %s \n", argv[1]);

    // ligne 2
    printf("Taille : %ld  Blocs : %ld  Blocs d'E/S : %ld \n", spointeur->st_size, spointeur->st_blksize, spointeur->st_blocks);

    // ligne 3
    printf("Périphérique : %li  Inœud : %ld  Liens : %ld \n", spointeur->st_rdev, spointeur->st_ino, spointeur->st_nlink);

    // ligne 4, on récupère le nom d'utilisateur avant l'affichage
    printf("UID : ( %i/  %s)   GID : ( %i/  %s)\n", spointeur->st_uid, pwd->pw_name, spointeur->st_gid, pwd->pw_name);

    // lignes avec dates
    struct timespec lastaccess = spointeur->st_atim;
    printFormattedDate(lastaccess, "Accès :");
    struct timespec lastmodif = spointeur->st_mtim;
    printFormattedDate(lastmodif, "Modif. :");
    struct timespec lastchange = spointeur->st_ctim;
    printFormattedDate(lastchange, "Changt :");

    // lignes en plus pour le mode (type de fichier et droits d'accès)
    int chmod = s.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
    printf("droits d'accès (chmod) : %o\n", chmod);

    if (S_ISDIR (s.st_mode)) {
        printf ("%s répertoire\n", FILE_TYPE_STRING);
    }
    else if (S_ISREG (s.st_mode)) {
        printf ("%s fichier\n", FILE_TYPE_STRING);
    }
    else if (S_ISFIFO (s.st_mode)) {
        printf ("%s FIFO\n", FILE_TYPE_STRING);
    }

    // fermeture des fd
    close(dirfd);
    close(fstatatfd);

    return 0;
}

