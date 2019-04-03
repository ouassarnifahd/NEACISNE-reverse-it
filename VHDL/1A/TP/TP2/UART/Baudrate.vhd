library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- BLOCK: Baudrate --

entity Baudrate is
    Port ( clk : in STD_LOGIC;
           tox_tx : out STD_LOGIC);
end Baudrate;

architecture Behavioral of Baudrate is

signal count : std_logic_vector (13 downto 0) :=(others=>'0');

begin

process(clk)

begin

     if rising_edge(clk) then
        if count = X"28A0" then
            count <= (others =>'0');
        else count <= count+1;
        end if;
    end if;
end process;

tox_tx <= '1' when count = X"28A0" else '0';

end Behavioral;
