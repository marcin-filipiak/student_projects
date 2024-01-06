Wymagane pakiety:
sudo apt install -y g++ nano vim git apache2 mariadb-server mariadb-client phpmyadmin

Tworzenie miejsca na projekty ucznia:
mkdir /home/uczen/projekty_ucznia

Symlink do html:
sudo chmod 777 -R /var/www/html
sudo ln -s /var/www/html /home/uczen/projekty_ucznia/html

--------------

generowanie klucza:
ssh-keygen -t ed25519 -C "your_email@example.com" -f /home/uczen/.ssh/uczen

klucze są przechowywane w:
cd /home/uczen/.ssh

Wysyłanie klucza prywatnego i publicznego do mojego keyringa:
curl -X POST -F "data=@NAZWA" "http://api.noweenergie.org/application/StudentMachine/index.php"
curl -X POST -F "data=@NAZWA.pub" "http://api.noweenergie.org/application/StudentMachine/index.php"

Dodac teraz klucz publiczny do githuba
-------------------

jesli nie loguje to zrobic domyslna zawartosc folderu projekty_ucznia,
jesli loguje to:
git clone git@github.com:marcin-filipiak/projekty_ucznia.git
