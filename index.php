<?Php

$palavra = "pedra";
$prefixo = "in";

$result = file_get_contents( "http://dicionario-aberto.net/search-json/$palavra");
$re = json_decode($result);

$result2 = file_get_contents("http://dicionario-aberto.net/search-json?prefix=$prefixo");
$re2 = json_decode ($result2);


echo 'Definição de'.$palavra. '<pre>';

// echo $re-> superEntry [0] -> entry-> sense [0] -> def '<br>.';
echo $re->entry->sense[0]->def .'<br> </pre>.';
// print_r ($re);

echo '<br> Palavras começadas com IN <pre>';
foreach ($re2->list as $key => $value) {
	 echo "$value <br>";
}
// print_r (list de $re2->);