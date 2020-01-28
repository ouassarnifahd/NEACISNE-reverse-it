----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 29.11.2018 10:09:42
-- Design Name: 
-- Module Name: delay - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity delay is
    Port ( clk : in STD_LOGIC;
           RST : in STD_LOGIC;
           DELAY_EN : in STD_LOGIC;
           DELAY_MS : in STD_LOGIC_VECTOR (11 downto 0);
           DELAY_FIN : out STD_LOGIC);
end delay;

architecture Behavioral of delay is
    type etat_type is(debut , tempo,fin);
    signal etat : etat_type := debut;
    signal count : std_logic_vector(16 downto 0);
    signal count_ms : std_logic_vector(11 downto 0);

begin
    process(clk)
    begin
        if rising_edge(clk) then
            if RST='1' then
                etat<=debut;
            else
                case etat is
                    when debut =>
                       DELAY_FIN<='0';
                       if DELAY_EN ='1' then
                        etat <= tempo;
                       end if;
                    when tempo =>
                        DELAY_FIN<='0';
                        if (count_ms=DELAY_MS) then
                            etat <= fin;
                        end if;
                    when fin => 
                    DELAY_FIN<='1';
                    if (DELAY_EN='0') then
                        etat <= debut;
                    end if;
                     
                end case;
                    
            end if; 
        end if;
    end process;



    process(clk)
    begin
        if rising_edge(clk) then
            if RST='1' then
                 count_ms<=(others=>'0');
                 count<=(others=>'0');
            elsif etat = tempo then
                if count =x"186A0" then
                    count <= (others=>'0');
                    count_ms <= count_ms+1;
                    else
                        count <= count +1;
                end if;
            else
                count_ms<=(others=>'0');   
            end if; 
        end if;
    end process;


end Behavioral;
