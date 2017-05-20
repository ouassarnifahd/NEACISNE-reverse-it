library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity compteur is
    Port ( clk : in STD_LOGIC;
           TTL_mef : in STD_LOGIC;
           valid : in STD_LOGIC;
           raz : in STD_LOGIC;
           freq(15:0) : out STD_LOGIC);
end compteur;

architecture Behavioral of compteur is

begin


end Behavioral;
