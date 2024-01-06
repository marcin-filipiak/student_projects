Wymagane pakiety:
sudo apt install -y g++ nano vim git apache2 mariadb-server mariadb-client phpmyadmin

Tworzenie miejsca na projekty ucznia:
mkdir ~/projekty_ucznia

Symlink do html:
sudo chmod 777 -R /var/www/html
sudo ln -s /var/www/html ~/projekty_ucznia/html

--------------

generowanie klucza, używaj passphrase żeby zabezpieczyć klucz prywatny:
ssh-keygen -t ed25519 -C "your_email@example.com" -f /home/uczen/.ssh/uczen

klucze są przechowywane w:
cd ~/.ssh

Wysyłanie klucza prywatnego i publicznego do mojego keyringa:
curl -X POST -F "data=@~/.ssh/NAZWA" "http://api.noweenergie.org/application/StudentMachine/index.php"
curl -X POST -F "data=@~/.ssh/NAZWA.pub" "http://api.noweenergie.org/application/StudentMachine/index.php"

klucz prywatny musi być niedostępny dla innych, należy ustawić prawa do pliku:
chmod 600 ~/.ssh/NAZWA

możliwe że trzeba włączyć agenta dla sesji terminala:
eval "$(ssh-agent -s)"

dodać klucz do ssh:
ssh-add ~/.ssh/NAZWA

Dodac teraz klucz publiczny do githuba
-------------------

jesli nie loguje to zrobic domyslna zawartosc folderu projekty_ucznia,
jesli loguje to:

ustaw gita zgodnie z ustawieniami na github:
git config --global user.email "user@example.com"
git config --global user.name "user"

sklonuj repozytorium:
git clone git@github.com:marcin-filipiak/projekty_ucznia.git


po wykonaniu pracy:
cd ~/projekty_ucznia
git add .
git commit -m "wyslanie pracy"
git push
